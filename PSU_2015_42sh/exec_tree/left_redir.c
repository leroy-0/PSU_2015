/*
** left_redir.c for left_redir in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue May 24 13:44:26 2016 Yan Poinssot
** Last update Sun Jun  5 20:52:40 2016 bruere_s
*/

#include        <fcntl.h>
#include        <sys/types.h>
#include	<stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include	<string.h>
#include	"get_next_line.h"
#include	"exec_tree.h"
#include	"exec.h"
#include        "node.h"
#include	"my.h"

int		left_redir(t_tree *branch, char ***env)
{
  int		save;
  int		new_fd;
  int		back;

  if (check_below(branch) == 1)
    return (1);
  if ((save = dup(0)) == -1)
    return (send_err("Error dup", "System call failed\n", 1));
  if ((new_fd = open(branch->right->node->line, O_RDONLY)) == -1)
    {
      my_puterr(branch->right->node->line);
      my_puterr(": No such file or directory.\n");
    }
  if (dup2(new_fd, 0) == -1)
    return (1);
  back = manage(branch->left, env);
  if (dup2(save, 0) == -1)
    return (1);
  close(save);
  close(new_fd);
  return (back);
}

static char		*get_text(char *res, char *tmp, char *str)
{
  if (res)
    {
      tmp = my_x_malloc(sizeof(char)
		   * (my_strlen(res) + my_strlen(str) + 2));
      tmp = strcpy(tmp, res);
      tmp = strcat(tmp, str);
      tmp = strcat(tmp, "\n");
      res = my_x_malloc(sizeof(char) * (my_strlen(tmp) + 2));
      res = strcpy(res, tmp);
    }
  else
    {
      res = my_x_malloc(sizeof(char) * (my_strlen(str) + 2));
      res = strcpy(res, str);
      res = strcat(res, "\n");
    }
  return (res);
}

char		*check_get_dredirl(t_tree *branch)
{
  char		*res;
  char		*tmp;
  char		*str;
  int		i;

  i = 0;
  res = NULL;
  tmp = NULL;
  str = NULL;
  if (check_below(branch) == 1)
    return (NULL);
  if (isatty(0) != 0)
    my_putstr("> ");
  while ((str = get_next_line(0)) != NULL && i < 4096)
    {
      if (isatty(0) != 0)
	my_putstr("> ");
      if ((res = get_text(res, tmp, str)) == NULL)
	return (NULL);
      if (strcmp(str, branch->right->node->line) == 0)
	return (res);
      i++;
    }
  return (res);
}

int		check_for_left_redir(char *str, char ***env)
{
  char		**path_tab;
  char		*path;
  char		**cmd;

  path = NULL;
  path_tab = NULL;
  cmd = str_to_wordtab(str, ' ');
  if ((path_tab = str_to_wordtab(my_search_env("PATH", *env), ':')) == NULL)
    {
      if (access(str, X_OK) == 0 && (is_direct_path(str) == 0))
	return (0);
      return (1);
    }
  path_tab = put_slash_in_path(path_tab);
  if (cmd[0] != NULL)
    {
      if ((path = find_good_path(path_tab, cmd[0])) == NULL)
	return (1);
      return (0);
    }
  return (1);
}

int		left_dredir(t_tree *branch, char ***env)
{
  char		*res;
  int		save;
  int		result;
  int		tmpfd[2];

  result = 0;
  if ((res = check_get_dredirl(branch)) == NULL)
    return (1);
  pipe(tmpfd);
  if (res != NULL && res[0] != '\0')
    write(tmpfd[1], res, strlen(res));
  close(tmpfd[1]);
  save = dup(0);
  dup2(tmpfd[0], 0);
  result = 0;
  if (branch->left->node->func != NULL)
    return (manage(branch->left, env));
  result = exec_fork(branch->left->node->line, env, 0, &result);
  close(tmpfd[0]);
  dup2(save, 0);
  return (result);
}

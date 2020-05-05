/*
** left_redir.c for left_redir in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue May 24 13:44:26 2016 Yan Poinssot
** Last update Sun Jun  5 23:33:39 2016 longle_h
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
#include	"bonus.h"
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
      if ((tmp = my_x_malloc(sizeof(char)
			* (my_strlen(res) + my_strlen(str) + 2))) == NULL)
	return (NULL);
      tmp = strcpy(tmp, res);
      tmp = strcat(tmp, str);
      tmp = strcat(tmp, "\n");
      if ((res = my_x_malloc(sizeof(char) * (my_strlen(tmp) + 2))) == NULL)
	return (NULL);
      res = strcpy(res, tmp);
    }
  else
    {
      if ((res = my_x_malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
	return (NULL);
      res = strcpy(res, str);
      res = strcat(res, "\n");
    }
  return (res);
}

int		init_args(int *i, t_tree *branch)
{
  (*i) = 0;
  if (check_below(branch) == 1)
    return (1);
  if (isatty(0) != 0)
    my_putstr("> ");
  return (0);
}

char		*check_get_dredirl(t_tree *branch, char **env)
{
  char		*res;
  char		*tmp;
  char		*str;
  int		i;

  res = NULL;
  tmp = NULL;
  if ((init_args(&i, branch)) == 1)
    return (NULL);
  if (init_term(1, env) == 1)
    return (NULL);
  while ((str = my_getstr(env)) != NULL && i < 4096)
    {
      if (isatty(0) != 0)
	my_putstr("> ");
      if ((res = get_text(res, tmp, str)) == NULL)
	return (NULL);
      if (strcmp(str, branch->right->node->line) == 0)
	return (res);
      i++;
    }
  if (init_term(0, env) == 1)
    return (NULL);
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

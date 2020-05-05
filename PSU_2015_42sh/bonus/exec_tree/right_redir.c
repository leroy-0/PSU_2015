/*
** right_redir.c for right_redir in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue May 24 13:44:39 2016 Yan Poinssot
** Last update Sat Jun  4 17:54:07 2016 Yan Poinssot
*/

#include        <fcntl.h>
#include        <sys/types.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include	"node.h"
#include	"exec_tree.h"
#include	"my.h"

int		right_redir(t_tree *branch, char ***env)
{
  int		save;
  int		new_fd;
  int		back;

  if (check_below(branch) == 1)
    return (1);
  new_fd = 0;
  if ((save = dup(1)) == -1)
    return (send_err("Error dup :", "System call failed\n", 1));
  if ((new_fd = open(branch->right->node->line, O_WRONLY
		     | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR)) == -1)
    return (send_err("Error open", "System call failed\n", 1));
  if (dup2(new_fd, 1) == -1)
    return (send_err("Error dup2", "System call failed\n", 1));
  back = manage(branch->left, env);
  if (dup2(save, 1) == -1)
    {
      my_puterr("Error : System call failed\n");
      return (1);
    }
  close(save);
  close(new_fd);
  return (back);
}

int		right_dredir(t_tree *branch, char ***env)
{
  int		save;
  int		new_fd;
  int		back;

  if (check_below(branch) == 1)
    return (1);
  new_fd = 0;
  if ((save = dup(1)) == -1)
    return (send_err("Error dup :", "System call failed\n", 1));
  if ((new_fd = open(branch->right->node->line, O_WRONLY | O_APPEND
		     | O_CREAT, S_IWUSR | S_IRUSR)) == -1)
    return (send_err("Error open", "System call failed\n", 1));
  if (dup2(new_fd, 1) == -1)
    return (send_err("Error dup2", "System call failed\n", 1));
  back = manage(branch->left, env);
  if (dup2(save, 1) == -1)
    {
      my_puterr("Error : System call failed\n");
      return (1);
    }
  close(save);
  close(new_fd);
  return (back);
}

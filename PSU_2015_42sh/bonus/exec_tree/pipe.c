/*
** pipe.c for pipe in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue May 24 13:47:01 2016 Yan Poinssot
** Last update Sun Jun 05 19:08:52 2016 Arthur KLEIN
*/

#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"exec_tree.h"
#include	"node.h"
#include	"exec.h"
#include	"my.h"

int		check_the_null_command(t_tree *tree, int *pos)
{
  if (tree->left->node->line == NULL || tree->right->node->line == NULL)
    {
      my_puterr("Invalid null command.\n");
      *pos = 0;
      return (1);
    }
  return (0);
}

int	return_my_value(int *pos, t_tree *tree, int *save, t_return *my_ret)
{
  *pos = 0;
  if (((WIFEXITED(my_ret->res)
	&& WEXITSTATUS(my_ret->res) == 1) || my_ret->res != 0) && *save == 0)
    *save = 1;
  else if (WIFSIGNALED(my_ret->res))
    my_ret->res = write_seg(my_ret->res, tree->node->line);
  if (*save == 1)
    my_ret->res = *save;
  if (my_ret->ret == 0)
    return (my_ret->res);
  else
    return (my_ret->ret);
}

int	check_and_init_pipe(t_tree *tree, int *pos, int *saveout,
			    int (*p_fd)[2])
{
  int	pid;

  pid = 0;
  if (check_below(tree) == 1)
    return (1);
  if (*pos == 0)
    *saveout = dup(0);
  *pos = 1;
  if (gest_error(tree, p_fd, pid) == 1)
    return (1);
  return (0);
}

void	init_my_all(int *pid, int *saveout, int (*p_fd)[2], t_return *my_ret)
{
  my_ret->res = 0;
  my_ret->ret = 0;
  *pid = 0;
  *saveout = 0;
  (*p_fd)[0] = 0;
  (*p_fd)[1] = 0;
}

int			my_pipe(t_tree *tree, char ***env)
{
  static int		fd = 0;
  pid_t			pid;
  int			saveout;
  t_return		my_ret;
  int			p_fd[2];
  static int		save = 0;
  static int		pos = 0;

  init_my_all(&pid, &saveout, &p_fd, &my_ret);
  if (check_and_init_pipe(tree, &pos, &saveout, &p_fd) == 1)
    return (1);
  pid = fork();
  if (pid == 0)
    my_ret.ret = execute_left(p_fd, fd, tree, env);
  else
    my_ret.ret = execute_right(p_fd , &fd, tree, env);
  waitpid(pid, &my_ret.res, 0);
  dup2(saveout, 0);
  close(saveout);
  return (return_my_value(&pos, tree, &save, &my_ret));
}

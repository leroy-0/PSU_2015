/*
** manage.c for manage in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed May 25 01:15:43 2016 Yan Poinssot
** Last update Sat Jun  4 16:55:15 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"exec.h"
#include	"exec_tree.h"
#include	"node.h"
#include	"my.h"

int		check_redir(t_tree *branch)
{
  int		back;

  back = 0;
  if (manage_redir_error(branch) == 1)
    return (1);
  if (branch->left->node->priority == 5 ||
      branch->left->node->priority == 4)
    back = check_redir(branch->left);
  if (back == 0 && (branch->right->node->priority == 5 ||
		    branch->right->node->priority == 4))
    back = check_redir(branch->right);
  return (back);
}

int		manage_redir_error(t_tree *branch)
{
  if (branch->right->node->line == NULL ||
      branch->right->node->line[0] == '\0')
    {
      my_puterr("Missing name for redirect.\n");
      return (1);
    }
  else if (branch->left->node->line == NULL ||
      branch->left->node->line[0] == '\0')
    {
      my_puterr("Invalid null command.\n");
      return (1);
    }
  return (0);
}

int		manage(t_tree *branch, char ***env)
{
  int		pid;
  int		ret;
  int		res;
  t_built	*in;

  ret = 0;
  pid = 0;
  in = my_x_malloc(sizeof(t_built) * 7);
  if (branch != NULL && branch->right == NULL && branch->left == NULL)
    {
      if ((res = fill_ptr_fnc(in, branch->node->line, env)) == 2)
	{
	  ret = exec_fork(branch->node->line, env, pid, &ret);
	}
      else if (res == 1)
	return (1);
    }
  else if (branch != NULL)
    return (branch->node->func(branch, env));
  return (ret);
}

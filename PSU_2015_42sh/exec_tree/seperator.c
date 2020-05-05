/*
** seperator.c for multiple in /home/poinss_y/Documents/PSU/PSU_2015_42sh
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed May 18 15:12:00 2016 Yan Poinssot
** Last update Sun Jun  5 19:38:48 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	"exec_tree.h"
#include	"exec.h"
#include	"node.h"
#include	"my.h"

int		exec(char *line, char ***env, int pid, int *ret)
{
  *ret = my_simple_exec(line, env, pid, ret);
  return (*ret);
}

int		exec_fork(char *line, char ***env, int pid, int *ret)
{
  int		save;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    *ret = exec(line, env, pid, ret);
  waitpid(pid, &save, 0);
  if (WIFSIGNALED(save))
    *ret = write_seg(save, line);
  if (WIFEXITED(save) == 1 && WEXITSTATUS(save) == 1)
    {
      *ret = 1;
      return (*ret);
    }
  return (*ret % 255);
}

int		seperate(t_tree *branch, char ***env)
{
  int		stat_left;

  stat_left = 0;
  if (branch->left->node->line != NULL)
    stat_left = manage(branch->left, env);
  if (branch->right->node->line != NULL)
    stat_left = manage(branch->right, env);
  return (stat_left);
}

int		and(t_tree *branch, char ***env)
{
  int		stat_left;
  int		stat_right;

  stat_left = 0;
  stat_right = 0;
  if (check_below(branch) == 1)
    return (1);
  if (branch->left->node->line != NULL)
    stat_left = manage(branch->left, env);
  if (stat_left == 0 && branch->right->node->line != NULL)
    stat_right = manage(branch->right, env);
  if (stat_left == 1 || stat_right == 1)
    return (1);
  return (0);
}

int		or(t_tree *branch, char ***env)
{
  int		temp;

  if (check_below(branch) == 1)
    return (1);
  if (branch->left->node->line != NULL &&
      (temp = manage(branch->left, env) != 1))
    return (0);
  return (manage(branch->right, env));
}

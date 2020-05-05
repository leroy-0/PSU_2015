/*
** check_tree.c for check_tree in /home/poinss_y/Documents/PSU/PSU_2015_42sh/check_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 16:57:07 2016 Yan Poinssot
** Last update Wed Jun  8 20:19:54 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	"my.h"
#include	"exec_tree.h"
#include	"node.h"

static int	check_and(t_tree *branch)
{
  int		back;

  back = 0;
  if (branch->right->node->line == NULL ||
      (branch->right->node->line == NULL && branch->left->node->line != NULL))
    {
      my_putstr("Invalid null command\n");
      back = 1;
    }
  if (back == 0)
    back = check_below(branch->left);
  if (back == 0)
    back = check_below(branch->right);
  return (back);
}

static int	check_or(t_tree *branch)
{
  int		back;

  back = 0;
  if (branch->right->node->line == NULL ||
      branch->left->node->line == NULL)
    {
      my_putstr("Invalid null command\n");
      back = 1;
    }
  if (back == 0)
    back = check_below(branch->left);
  if (back == 0)
    back = check_below(branch->right);
  return (back);
}

static int	ok(t_tree *branch)
{
  int		back;

  back = 0;
  back = check_below(branch->left);
  if (back == 0)
    back = check_below(branch->right);
  return (back);
}

static int	check_pipe(t_tree *branch)
{
  int		back;

  back = 0;
  if (branch->left->node->line == NULL ||
      branch->left->node->line[0] == '\0' ||
      branch->right->node->line == NULL ||
      branch->right->node->line[0] == '\0')
    {
      my_puterr("Invalid null command.\n");
      return (1);
    }
  back = check_below(branch->left);
  if (back == 0)
    back = check_below(branch->right);
  return (back);
}

int		check_below(t_tree *branch)
{
  static int	(*check[2])(t_tree *);
  int		index;

  check[0] = &check_and;
  check[1] = &check_or;
  if (branch->node->func == NULL)
    return (0);
  else if (branch->node->priority == 1)
    return (ok(branch));
  else if (branch->node->priority == 2)
    {
      if (my_strcmp(branch->node->line, "&&") == 0)
	index = 0;
      else
	index = 1;
      return (check[index](branch));
    }
  else if (branch->node->priority == 3)
    return (check_pipe(branch));
  return (check_redir(branch));
}

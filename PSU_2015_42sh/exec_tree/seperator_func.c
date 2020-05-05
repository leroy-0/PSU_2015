/*
** seperator_func.c for seperator_func in /home/poinss_y/Documents/PSU/PSU_2015_42sh/exec_tree
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Wed Jun  1 16:30:31 2016 Yan Poinssot
** Last update Sun Jun  5 19:14:49 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	"node.h"
#include	"exec_tree.h"
#include	"my.h"

static int	choose(char *op)
{
  if (my_strcmp(op, "&&") == 0)
    return (0);
  return (1);
}

int		check_and(t_tree *branch)
{
  int		back;
  int		(*check[2])(t_tree *);

  check[0] = &check_and;
  check[1] = &check_or;
  back = 0;
  if (branch->right->node->priority == 1)
    back = check[choose(branch->right->node->line)](branch->right);
  if (back == 0 && branch->left->node->priority == 1)
    back = check[choose(branch->left->node->line)](branch->right);
  if (branch->right->node->line == NULL ||
      (branch->right->node->line == NULL && branch->left->node->line != NULL))
    {
      my_putstr("Invalid null command\n");
      back = 1;
    }
  return (back);
}

int		check_or(t_tree *branch)
{
  int		back;
  int		(*check[2])(t_tree *);

  check[0] = &check_and;
  check[1] = &check_or;
  back = 0;
  if (branch->right->node->priority == 1)
    back = check[choose(branch->right->node->line)](branch->right);
  if (back == 0 && branch->left->node->priority == 1)
    back = check[choose(branch->left->node->line)](branch->right);
  if (branch->right->node->line == NULL ||
      branch->left->node->line == NULL)
    {
      my_putstr("Invalid null command\n");
      back = 1;
    }
  return (back);
}

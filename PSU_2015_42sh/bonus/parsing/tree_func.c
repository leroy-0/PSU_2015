/*
** tree_func.c for tree_func in /home/poinss_y/Documents/PSU/PSU_2015_42sh/parsing
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 12 11:31:54 2016 Yan Poinssot
** Last update Sun Jun  5 23:35:04 2016 longle_h
*/

#include	<stdlib.h>
#include	<string.h>
#include	"my.h"
#include	"node.h"

static int	analyse_line(char *line, t_node *node, int pos)
{
  char		*tmp;
  int		back;

  back = 0;
  tmp = extract(line, pos, pos + my_strlen(node->line));
  if (strcmp(tmp, node->line) == 0)
    back = 1;
  free(tmp);
  return (back);
}

static int	analyse_pos(char *line, t_analyse *analyse, int pos)
{
  int		index;

  index = 0;
  while (index < 8)
    {
      if (analyse->select[index] == 1)
	{
	  if (analyse_line(line, analyse->op[index], pos) == 1)
	    return (index);
	}
      index++;
    }
  return (-1);
}

int		analyse_branch(t_tree *tree, t_analyse *analyse)
{
  int		a;
  int		back;
  int		index;

  a = 0;
  back = 0;
  if (tree->node->line == NULL)
    return (0);
  while (tree->node->priority < 0 && back == 0 &&
	 tree->node->line[a] != '\0')
    {
      if ((index = analyse_pos(tree->node->line, analyse, a)) != -1)
	back = analyse->split[index](tree, analyse->op[index], a);
      a++;
    }
  if (back != 1 && tree->left != NULL)
    back = analyse_branch(tree->left, analyse);
  if (back != 1 && tree->right != NULL)
    back = analyse_branch(tree->right, analyse);
  return (back);
}

t_tree		*create_branch(t_tree *previous, t_node *info)
{
  t_tree	*back;

  if ((back = my_x_malloc(sizeof(t_tree))) == NULL)
    {
      my_puterr("Error : Memory allocation failure\n");
      return (NULL);
    }
  back->previous = previous;
  back->node = info;
  back->left = NULL;
  back->right = NULL;
  return (back);
}

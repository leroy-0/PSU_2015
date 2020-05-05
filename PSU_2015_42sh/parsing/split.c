/*
** split.c for split in /home/poinss_y/Documents/PSU/PSU_2015_42sh/parsing
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Fri May 13 17:41:11 2016 Yan Poinssot
** Last update Sun Jun  5 21:02:01 2016 bruere_s
*/

#include	<stdlib.h>
#include	<string.h>
#include	"node.h"
#include	"my.h"

int		split(t_tree *tree, t_node *node, int pos)
{
  char		*tmp;
  char		*tmps;
  t_node	*left;
  t_node	*right;

  tmp = extract(tree->node->line, 0, pos);
  tmps = extract(tree->node->line, pos + my_strlen(node->line),
		 my_strlen(tree->node->line));
  if ((left = create_node(tmp, -1, NULL)) == NULL ||
      (right = create_node(tmps, -1, NULL)) == NULL)
    return (1);
  if ((tree->left = create_branch(tree, left)) == NULL||
      (tree->right = create_branch(tree, right)) == NULL)
    return (1);
  free(tree->node->line);
  free(tmp);
  free(tmps);
  tree->node->line = strdup(node->line);
  tree->node->priority = node->priority;
  tree->node->func = node->func;
  return (2);
}

int		split_redir(t_tree *tree, t_node *node, int pos)
{
  int		a;
  char		*tmp;
  char		*tmps;
  char		*temp;
  t_node	*left;
  t_node	*right;

  a = pos + my_strlen(node->line) + 1;
  tmp = extract(tree->node->line, 0, pos);
  while (a < my_strlen(tree->node->line) && tree->node->line[a] != ' ' &&
	 tree->node->line[a] != '\t')
    a++;
  tmps = extract(tree->node->line, a, my_strlen(tree->node->line));
  temp = extract(tree->node->line, pos + my_strlen(node->line), a);
  if ((left = create_node(stitch(tmp, tmps, " "), -1, NULL)) == NULL ||
      (right = create_node(temp, -1, NULL)) == NULL)
    return (1);
  if ((tree->left = create_branch(tree, left)) == NULL ||
      (tree->right = create_branch(tree, right)) == NULL)
    return (1);
  free(tree->node->line);
  tree->node->line = strdup(node->line);
  tree->node->priority = node->priority;
  tree->node->func = node->func;
  return (2);
}

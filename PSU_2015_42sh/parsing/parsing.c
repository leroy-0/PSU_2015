/*
** parsing.c for parsing in /home/klein_h/Documents/rendu/PSU_2015_42sh/parsing
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Apr 28 15:04:20 2016 klein_h
** Last update Mon May 30 21:11:28 2016 bruere_s
*/

#include	<stdlib.h>
#include	"node.h"
#include	"my.h"

static int	create_tree(t_tree *tree, t_analyse *analyse)
{
  char		count;

  count = 1;
  while (count < 6)
    {
      set_priorities(analyse, count);
      if (analyse_branch(tree, analyse) == 1)
	return (1);
      count++;
    }
  return (0);
}

t_tree		*parse(char *line)
{
  t_tree	*tree;
  t_node	*start;
  t_analyse	*analyse;

  analyse = set_analyse();
  start = create_node(line, -1, NULL);
  tree = create_branch(NULL, start);
  if (create_tree(tree, analyse) == 1)
    return (NULL);
  return (tree);
}

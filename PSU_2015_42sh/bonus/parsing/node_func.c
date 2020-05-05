/*
** node_func.c for node_functions in /home/poinss_y/Documents/PSU/PSU_2015_42sh/parsing
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 12 11:34:14 2016 Yan Poinssot
** Last update Sun Jun  5 23:34:47 2016 longle_h
*/

#include	<stdlib.h>
#include	<string.h>
#include	"my.h"
#include	"node.h"

void		free_node(t_node **node)
{
  if ((*node)->line != NULL)
    free((*node)->line);
  if ((*node)->func != NULL)
    free((*node)->func);
  free(*node);
}

t_node		*create_node(char *line, char priority, t_function function)
{
  t_node	*back;

  if ((back = my_x_malloc(sizeof(t_node))) == NULL)
    {
      my_puterr("Error : Memory allocation failure\n");
      return (NULL);
    }
  back->line = flatten(line);
  back->priority = priority;
  back->func = function;
  return (back);
}

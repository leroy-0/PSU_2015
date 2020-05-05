/*
** list_functions.c for list_functions in /home/poinss_y/Documents/PSU/PSU_2015_42sh
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue May 31 19:13:33 2016 Yan Poinssot
** Last update Sun Jun  5 23:50:31 2016 bruere_s
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"bonus.h"
#include	"my.h"

void		swap(t_linked *first, t_linked *second)
{
  t_linked	*tmp;

  tmp = first->next;
  first->next = second->next;
  second->next = tmp;
  tmp = first->previous;
  first->previous = second->previous;
  second->previous = tmp;
}

t_data		*create_data(char *name)
{
  t_data	*new;

  new = my_x_malloc(sizeof(t_linked));
  new->name = strdup(name);
  new->status = 0;
  return (new);
}

int		add_item(t_linked **next, t_data *data)
{
  t_linked	*new;

  new = my_x_malloc(sizeof(t_linked));
   new->previous = *next;
  new->next = NULL;
  new->data = data;
  if (*next != NULL)
    (*next)->next = new;
  *next = new;
  return (0);
}

void		free_item(t_linked **item)
{
  if ((*item)->next != NULL)
    (*item)->next = (*item)->previous;
  if ((*item)->previous != NULL)
    (*item)->previous = (*item)->next;
  free((*item)->data->name);
  free((*item)->data);
  free(*item);
}

void		free_list(t_linked **item)
{
  if ((*item)->next == NULL)
    free_list(&((*item)->next));
  free((*item)->data->name);
  free((*item)->data);
  free(*item);
}

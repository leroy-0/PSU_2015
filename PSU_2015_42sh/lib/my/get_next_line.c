/*
** get_next_line.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/get_next_line.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:03:47 2016 Arthur KLEIN
** Last update Sun Jun  5 21:28:16 2016 leroy_0
*/

#include	<sys/types.h>
#include	<sys/uio.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"
#include	"my.h"

int		end_or_size(t_list *string, int j)
{
  t_list	*tmp;
  int		cpt;

  tmp = string;
  cpt = 0;
  while (tmp != NULL)
    {
      if (tmp->data == '\n' || tmp->data == '\0')
	{
	  if (j == 0)
	    return (-1);
	  else
	    return (cpt);
	}
      tmp = tmp->next;
      cpt++;
    }
  return (cpt);
}

void		my_free_end(t_list **string)
{
  t_list	*tmp_save;

  tmp_save = *string;
  (*string) = (*string)->next;
  free(tmp_save);
}

char		*list_to_char(t_list **string, int j)
{
  char		*str;
  int		i;
  t_list	*tmp;

  i = 0;
  j = 1;
  if ((*string) == NULL)
    return (NULL);
  str = my_x_malloc(sizeof(char) * (end_or_size(*string, j) + 1));
  while (*string != NULL && (*string)->data != '\n' && (*string)->data != '\0')
    {
      str[i++] = (*string)->data;
      tmp = *string;
      *string = (*string)->next;
      free(tmp);
    }
  str[i] = '\0';
  if ((*string) != NULL)
    my_free_end(string);
  return (str);
}

t_list			*my_put_in_list(t_list *string, char data)
{
  static t_list		*save = NULL;
  t_list		*letter;

  letter = my_x_malloc(sizeof(t_list));
  letter->data = data;
  letter->next = NULL;
  if (string == NULL)
    {
      save = letter;
      return (save);
    }
  save->next = letter;
  save = letter;
  return (string);
}

char			*get_next_line(const int fd)
{
  static t_list		*string = NULL;
  static int		j = 0;
  int			i;
  int			ret;
  char			buffer[READ_SIZE];

  i = 0;
  if (fd == -1)
    return (NULL);
  if ((ret = read(fd, buffer, READ_SIZE - 1)) < 0)
    return (NULL);
  else if (ret == 0)
    return (list_to_char(&string, j));
  while (i < ret)
    string = my_put_in_list(string, buffer[i++]);
  if (end_or_size(string, j) == -1)
    return (list_to_char(&string, j));
  return (get_next_line(fd));
}

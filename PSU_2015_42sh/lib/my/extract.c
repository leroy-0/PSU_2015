/*
** extract.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/extract.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:07:49 2016 Arthur KLEIN
** Last update Sun Jun  5 21:29:34 2016 leroy_0
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		*extract(char *word, int start, int end)
{
  char		*back;
  int		count;

  if (start == end || word == NULL || start >= end)
    return (NULL);
  back = my_x_malloc(sizeof(char) * (end - start + 2));
  count = -1;
  while (word[++count + start] != '\0' && count + start < end)
    back[count] = word[count + start];
  back[count] = '\0';
  return (back);
}

static int	get_length(char *conv)
{
  int		count;
  int		c;

  count = 0;
  c = 0;
  while (conv[count] != '\0')
    {
      if (((conv[count] == ' ' || conv[count] == '\t') &&
	   (conv[count + 1] != ' ' && conv[count + 1] != '\t')) ||
	  (conv[count] != ' ' && conv[count] != '\t'))
	c++;
      count++;
    }
  return (c);
}

char		*flatten(char *conv)
{
  char		*back;
  int		count;
  int		check;
  int		c;

  if (conv == NULL)
    return (NULL);
  back = my_x_malloc(sizeof(char) * (get_length(conv) + 1));
  c = 0;
  count = 0;
  check = 0;
  while (conv[c] != '\0')
    {
      if (((conv[c] == ' ' || conv[c] == '\t') &&
	   (conv[c + 1] != ' ' && conv[c + 1] != '\t' && conv[c + 1] != '\0')
	   && check == 1) || (conv[c] != ' ' && conv[c] != '\t'))
	{
	  check = 1;
	  back[count] = (conv[c] == '\t') ? ' ' : conv[c];
	  count++;
	}
      c++;
    }
  back[count] = '\0';
  return (back);
}

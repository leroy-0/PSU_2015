/*
** extract.c for extract in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:50:40 2016 leroy_0
** Last update Sun Jun  5 23:24:51 2016 longle_h
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*extract(char *word, int start, int end)
{
  char		*back;
  int		count;

  if (start == end || word == NULL ||
      (back = my_x_malloc(sizeof(char) * (end - start + 2))) == NULL ||
      start >= end)
    return (NULL);
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

  if (conv == NULL ||
      (back = my_x_malloc(sizeof(char) * (get_length(conv) + 1))) == NULL)
    return (NULL);
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

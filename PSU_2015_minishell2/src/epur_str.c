/*
** epur_str.c for epur_str in 
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:03:28 2016 leroy_0
** Last update Thu Apr 21 10:08:05 2016 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char		*epur_str(char *str)
{
  char		*src;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (str && str[0] == '\0')
    return (NULL);
  if ((src = my_x_malloc(sizeof(char) * (my_strlen(str) + 50))) == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i++;
	  if (j > 0 && str[i] != '\0')
	    src[j++] = ' ';
	}
      src[j] = str[i];
      j++;
      i++;
    }
  src[j] = '\0';
  return (src);
}

char		*my_close_chaine(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	str[i] = '\0';
      i = i + 1;
    }
  return (str);
}

char		**my_close(char **tab, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      tab[i] = my_close_chaine(tab[i]);
      i = i + 1;
    }
  return (tab);
}

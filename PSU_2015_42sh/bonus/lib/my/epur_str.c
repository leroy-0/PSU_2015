/*
** epur_str.c for epur_str in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:53:25 2016 leroy_0
** Last update Sun Jun  5 23:23:11 2016 longle_h
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char		*epur_str(char *str)
{
  char		*tmp;
  int		i;
  int		k;

  i = 0;
  k = 0;
  tmp = my_x_malloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      tmp[k++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	{
	  tmp[k] = ' ';
	  k++;
	}
    }
  tmp[k] = '\0';
  free(str);
  return (tmp);
}

char		*my_close_chaine(char *str)
{
  int		i;

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

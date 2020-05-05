/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:55:39 2016 leroy_0
** Last update Sun Jun  5 23:22:28 2016 longle_h
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"../../include/my.h"

int			nb_word(char *str, char sep)
{
  int			i;
  int			nb;

  i = 0;
  nb = 0;
  while ((*str) == sep)
    (*str)++;
  while (str[i] != '\0')
    {
      if (str[i] != sep)
	{
	  nb++;
	  while (str[i + 1] != sep && str[i + 1] != '\0')
	    i++;
	}
      i++;
    }
  return (nb);
}

char			**str_to_wordtab(char *s, char sep)
{
  int			i;
  int			j;
  int			a;
  int			nb;
  char			**tab;

  i = 0;
  a = 0;
  j = 0;
  if (s == NULL)
    return (NULL);
  nb = nb_word(s, sep);
  tab = my_x_malloc(sizeof(char *) * (nb + 1));
  while (i < nb)
    {
      tab[i] = my_x_malloc(sizeof(char) * (my_strlen(s) + 1));
      while (s[a] != sep && s[a] != '\0')
	tab[i][j++] = s[a++];
      tab[i][j] = '\0';
      j = 0;
      a++;
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

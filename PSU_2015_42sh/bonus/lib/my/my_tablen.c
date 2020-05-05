/*
** my_tablen.c for my_tablen in /home/longle_h/rendu/PSU_2015_42sh/lib/my
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Fri May  6 15:25:58 2016 longle_h
** Last update Sun Jun  5 18:52:45 2016 leroy_0
*/

#include	<unistd.h>

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab && tab[i] != NULL)
    i++;
  return (i);
}

int		tablen(char **tab)
{
  int		i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}

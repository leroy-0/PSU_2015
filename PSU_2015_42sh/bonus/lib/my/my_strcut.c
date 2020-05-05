/*
** my_strcut.c for my_strcut in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Thu Jun  2 21:40:51 2016 bruere_s
** Last update Sun Jun  5 23:26:58 2016 longle_h
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

char		*my_str_cut(char *s, int j)
{
  char		*s2;
  int		i;

  i = 0;
  while (s[i] != '\0')
    i++;
  if (j > my_strlen(s))
    return (s);
  s2 = my_x_malloc(sizeof(char) * ((i - j) + 1));
  i = 0;
  while (s[j] && s[j] != '\0')
    {
      s2[i] = s[j];
      i++;
      j++;
    }
  s2[i] = '\0';
  return (s2);
}

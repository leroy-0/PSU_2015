/*
** my_strnbr.c for my_strnbr in /home/leroy_0/rendu/Piscine_C_evalexpr
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Oct 23 18:25:09 2015 maxime leroy
** Last update Tue Nov 10 16:45:47 2015 leroy_0
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

char	*unpositive(unsigned nb, char *str, unsigned int a, unsigned int x)
{
  if (nb >= 10)
    {
      while (nb != 0)
	{
	  a = nb % 10;
	  str[x] = '0' + a;
	  nb = nb / 10;
	  x++;
	}
      str[x] = '\0';
      my_revstr(str);
      return (str);
    }
  else
    {
      str[0] = '0' + nb;
      str[1] = '\0';
    }
  return (str);
}

char	*my_strunnbr(unsigned int nb)
{
  unsigned int	a;
  unsigned int	x;
  char	*str;

  a = nb;
  x = 0;
  while (a != 0)
    {
      a = a / 10;
      x++;
    }
  str = malloc((x + 1) * sizeof(char));
  a = 0;
  x = 0;
  return (unpositive(nb, str, a, x));
}

/*
** my_strnbr.c for my_strnbr in /home/leroy_0/rendu/Piscine_C_evalexpr
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Oct 23 18:25:09 2015 maxime leroy
** Last update Thu Feb 18 22:47:32 2016 Tekm
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

char	*my_strnbr(int nb, char *str)
{
  int		savenb;
  int		x;

  x = 0;
  savenb = nb;
  while (nb != 0)
    {
      str[x] = (nb % 10) + '0';
      nb = nb / 10;
      x++;
    }
  if (savenb < 0)
    {
      str[x] = '-';
      x++;
    }
  str[x] = '\0';
  my_revstr(str);
  return (str);
}

/*
** my_revstr.c for my_revstr in /home/leroy_0/rendu/Piscine_C_J06/ex_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Oct  5 11:18:46 2015 maxime leroy
** Last update Thu Nov 12 22:08:36 2015 leroy_0
*/

#include "../../include/my.h"

char	*my_revstr(char *str)
{
  int x;
  int y;
  char z;

  x = 0;
  y = my_strlen(str) - 1;
  while (x < y)
    {
      z = str[x];
      str[x] = str[y];
      str[y] = z;
      x++;
      y--;
    }
  return (str);
}

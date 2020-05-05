/*
** my_strnbput.c for my_strnbput in /home/leroy_0/rendu/Piscine_C_evalexpr
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Oct 30 20:22:05 2015 maxime leroy
** Last update Thu Nov 12 15:39:53 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

char	*my_while(char *res, char *src, int x, int z)
{
  while (src[z] != '\0')
    {
      res[x] = src[z];
      x++;
      z++;
    }
  return (res);
}

char    *my_strnbput(char *dest, char *src, int nb)
{
  int x;
  int y;
  int z;
  char *res;

  res = malloc((my_strlen(src) + my_strlen(dest)) * sizeof(char));
  if (res == NULL)
    return (0);
  x = 0;
  while (x < nb)
    {
      res[x] = src[x];
      x++;
    }
  z = x;
  y = 0;
  while (dest[y] != '\0')
    {
      res[x] = dest[y];
      x++;
      y++;
    }
  res = my_while(res, src, x, z);
  return (res);
}

/*
** binary.c for binary in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov  9 21:43:58 2015 leroy_0
** Last update Thu Nov 12 18:51:05 2015 leroy_0
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

char	*binary(unsigned long nb, int base)
{
  char	*res;
  long long	a;

  a = 0;
  res = malloc(50);
  if (nb == 0)
    res[a] = '0';
  while (nb != 0)
    {
      res[a] = (nb % base) + '0';
      nb = nb / base;
      a++;
    }
  my_revstr(res);
  return (res);
}

char	*hexa(unsigned long nb, int basenb, char *base)
{
  char *res;
  long long 	a;
  long long	b;

  a = 0;
  b = 0;
  res = malloc(50);
  if (nb == 0)
    res[a] = '0';
  while (nb != 0)
    {
      b = nb % basenb;
      res[a] = base[b];
      nb = nb / basenb;
      a++;
    }
  my_revstr(res);
  return (res);
}

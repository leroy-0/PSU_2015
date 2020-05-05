/*
** binary.c for binary in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov  9 21:43:58 2015 leroy_0
** Last update Sat Feb 20 19:37:50 2016 Tekm
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

char		*check_strlen(char *res, int a)
{
  while (my_strlen(res) <= 7)
    {
      res[a] = '0';
      a++;
      res[a] = '\0';
    }
  return (res);
}

char		*base(unsigned char nb, int basenb, char *base)
{
  char		*res;
  unsigned char	a;
  unsigned char	b;

  a = 0;
  b = 0;
  res = malloc(50);
  while (nb != 0)
    {
      b = nb % basenb;
      res[a] = base[b];
      nb = nb / basenb;
      a++;
    }
  res[a] = '\0';
  res = check_strlen(res, a);
  my_revstr(res);
  return (res);
}

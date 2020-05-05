/*
** my_getnbr.c for my_getnbr in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:54:58 2016 leroy_0
** Last update Sun Jun  5 17:55:02 2016 leroy_0
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

int	my_neg(char *str, int i)
{
  int	dash;

  dash = 0;
  i = i - 1;
  while ((i >= 0 && (str[i] == '-' || str[i] == '+')))
    {
      if (str[i] == '-')
	dash++;
      i--;
    }
  return (dash);
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;
  int	neg;

  if (str == NULL)
    return (0);
  i = 0;
  res = 0;
  while (str[i] && (str[i] < '0' || str[i] > '9'))
    i++;
  neg = my_neg(str, i);
  while (str[i] && (str[i] >= '0' && str[i] <='9'))
    res = res * 10 + (str[i++] - '0');
  if ((neg % 2) == 0)
    return (res);
  else
    return (-res);
}

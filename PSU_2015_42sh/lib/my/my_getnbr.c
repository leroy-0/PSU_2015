/*
** my_getnbr.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/my_getnbr.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:11:04 2016 Arthur KLEIN
** Last update Sat Jun 04 19:11:04 2016 Arthur KLEIN
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

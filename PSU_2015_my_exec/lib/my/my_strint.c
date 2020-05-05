/*
** my_strint.c for my_strint in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 15 19:10:19 2015 leroy_0
** Last update Sun Nov 15 19:17:45 2015 leroy_0
*/

#include <stdio.h>
#include "../../include/my.h"

int	my_strint(char *str)
{
  int	a;
  int	b;
  int	res;

  a = 0;
  b = 1;
  res = 0;
  if (str == NULL)
    return (0);
  if (str[0] == '-')
    {
      b = -1;
      a++;
    }
  while (str[a] != '\0')
    {
      res = res*10 + str[a] - '0';
      a++;
    }
  return (res*b);
}

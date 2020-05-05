/*
** my_getnbrchar.c for my_getnbrchar in /home/leroy_0/rendu/CPE_2015_BSQ/lib/my
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Dec  1 18:02:46 2015 leroy_0
** Last update Tue Dec  1 18:07:49 2015 leroy_0
*/

#include "../../include/my.h"

int     my_getnbrchar(char str)
{
  int a;
  int b;

  a = 1;
  b = 0;
  while (str == '-' || str == '+')
    {
      if (str == '-')
        a = - a;
      str = str + 1;
    }
  while (str != '\0' && str >= '0' && str <= '9')
    {
      if (b > 214748364)
        return (0);
      if (b == 214748364 && str > 7 && a == 1)
        return (0);
      if (b == 214748364 && str > 8 && a == -1)
        return (0);
      b = b * 10 + str - 48;
      str = str + 1;
    }
  if (a == -1)
    b = - b;
  return (b);
}

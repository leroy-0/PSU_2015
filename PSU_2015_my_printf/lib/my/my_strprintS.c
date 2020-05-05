/*
** my_strprintS.c for my_strprintS in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Nov 12 11:01:24 2015 leroy_0
** Last update Fri Nov 13 13:27:29 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

char	*my_strprintSprev(int a, int b, char *res, char *str)
{
  res[a] = '\\';
  if ((res[a + 2] < '0' || res[a + 2] > '9')
      && (res[a + 3] < '0' || res[a + 3] > '9'))
    {
      res[a + 1] = '0';
      my_strcat(res, hexa(str[b], 8, "01234567"));
    }
  return (res);
}

char	*my_strprintS(char *str)
{
  int	a;
  int	b;
  char	*res;

  a = 0;
  b = 0;
  res = malloc(my_strlen(str) * sizeof(char));
  while (str[b] != '\0')
    {
      if (str[b] >= 32 && str[b] < 127)
	res[a++] = str[b++];
      else
	{
	  res = my_strprintSprev(a, b, res, str);
	  if ((res[a + 2] >= '0' && res[a + 2] <= '9')
	      && (res[a + 3] < '0' || res[a + 3] > '9'))
	    {
	      res[a + 2] = '0';
	      my_strcat(res, hexa(str[b], 8, "01234567"));
	    }
	  a += 4;
	  b += 1;
	}
    }
  return (res);
}

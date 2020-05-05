/*
** my_main.c for my_main in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Nov 12 21:39:30 2015 leroy_0
** Last update Sun Nov 15 23:21:29 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

char	*my_result(char *res)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (res[a] == ' ')
    a++;
  if (a <= my_strlen(res) - a && res != "(null)")
    {
      while (a != my_strlen(res))
	res[b++] = res[a++];
      res[b] = '\0';
      return (res);
    }
  a = my_strlen(res) - a;
  if (a != my_strlen(res))
    {
      while (a != my_strlen(res))
	res[b++] = res[a++];
      res[b] = '\0';
    }
  return (res);
}

char	*my_condif3(int counter, char *s, va_list tmp, char *res)
{
  if (s[counter] == 'c')
    res[my_strlen(res)] = va_arg(tmp, int);
  if (s[counter] == 'S')
    res = my_strcat(res, my_strprintS(va_arg(tmp, char*)));
  if (s[counter] == 'b')
    res = my_strcat(res, binary(va_arg(tmp, unsigned int), 2));
  if (s[counter] == 'x')
    res = my_strcat(res, hexa(va_arg(tmp, unsigned int),
			      16, "0123456789abcdef"));
  if (s[counter] == 'X')
    res = my_strcat(res, hexa(va_arg(tmp, unsigned int),
			      16, "0123456789ABCDEF"));
  if (s[counter] == 'o')
    res = my_strcat(res, hexa(va_arg(tmp, unsigned int), 8, "01234567"));
  if (s[counter] == 'd' || s[counter] == 'i')
    res = my_strcat(res, (my_strnbr(va_arg(tmp, int))));
  if (s[counter] == 'u')
    res = my_strcat(res, my_strunnbr(va_arg(tmp, unsigned int)));
  return (res);
}

char    *my_condif(int counter, char *s, va_list tmp, char *res)
{
  char	*check;

  check = malloc(my_strlen(s) * sizeof(char));
  if (s[counter] == '%' || s[counter] == 'z')
    {
      res[my_strlen(res)] = '%';
      counter++;
    }
  if (s[counter] == 's')
    {
      check = va_arg(tmp, char*);
      if (check != NULL)
	res = my_strcat(res, check);
      else
	res = my_strcat(res, "(null)");
    }
  res = my_condif3(counter, s, tmp, res);
  res = my_result(res);
  return (res);
}

char    *my_condif2(int counter, char *s, char *res)
{
  char	*temp;
  int	a;
  int	b;

  a = 0;
  b = 0;
  temp = malloc(my_strlen(s) * sizeof(char));
  while (s[counter] >= '0' && s[counter] <= '9')
    temp[a++] = s[counter++];
  if (a != 0)
    a = my_strint(temp);
  while (b != a)
    res[b++] = ' ';
  if (s[counter] != 'c' && s[counter] != 'd' && s[counter] != 'i'
      && s[counter] != 's' && s[counter] != 'S' && s[counter] != 'b'
      && s[counter] != 'x' && s[counter] != 'X' && s[counter] != 'o'
      && s[counter] != 'u' && s[counter] != 'p' && s[counter] != 'z'
      && s[counter] != '%')
    {
      res[0] = '%';
      res[1] = s[counter];
    }
  return (res);
}

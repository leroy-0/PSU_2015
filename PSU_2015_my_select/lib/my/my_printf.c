/*
** my_printf.c for my_printf in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov  2 16:56:06 2015 maxime leroy
** Last update Sun Nov 15 19:48:10 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

int	my_while_exec_prev(char *s, int counter)
{
  my_putchar(s[counter]);
  counter++;
  return (counter);
}

int	my_while_exec(char *s, int counter, va_list tmp, int res)
{
  int		a;

  a = 0;
  while (s[counter] != '\0')
    {
      if (s[counter] != '%')
	counter = my_while_exec_prev(s, counter);
      else
	{
	  a += -1;
	  counter++;
	  if (s[counter] == ' ' || s[counter] == '-')
	    counter++;
	  else
	    a += 1;
	  res += my_display(counter, s, tmp) - 2;
	  while (s[counter] >= '0' && s[counter] <= '9')
	    counter++;
	  if (s[counter] == ' ')
	    counter += 2;
	  else
	    counter += 1;
	}
    }
  return (res + counter + a);
}

int     my_exec(char *s, va_list tmp)
{
  int		counter;
  int		res;

  counter = 0;
  res = 0;
  return (my_while_exec(s, counter, tmp, res));
}

char	*my_while_printf(int a, int b, char *res, char *s)
{
  while (s[a] != '\0')
    {
      if (s[a] != '%' && s[a] != '\0')
	{
	  res[b] = s[a];
	  b++;
	  a++;
	}
      else
	{
	  res[b] = s[a];
	  a++;
	  b++;
	  res[b] = s[a];
	  while (s[a] == ' ' && s[a] != '\0')
	    a++;
	  if (s[a - 1] == ' ' && s[a] != '\0')
	    {
	      res[b] = ' ';
	      b++;
	    }
	}
    }
  return (res);
}

int	my_printf(char *s, ...)
{
  int		a;
  int		b;
  char		*res;
  va_list	tmp;

  a = 0;
  b = 0;
  res = malloc(my_strlen(s) * sizeof(char));
  va_start(tmp, s);
  res = my_while_printf(a, b, res, s);
  va_end(tmp);
  a = my_exec(res, tmp);
  free(res);
  return (a);
}

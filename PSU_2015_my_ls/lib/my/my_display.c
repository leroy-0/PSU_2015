/*
** my_display.c for my_display in /home/leroy_0/rendu/PSU_2015_my_printf
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Nov 15 19:49:22 2015 leroy_0
** Last update Sun Nov 15 19:50:37 2015 leroy_0
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

int     my_calc_data(char *s, char *res, int counter, int data)
{
  if (s[counter - 1] == ' ' && res[0] != '-'
      && (s[counter] != 'c' && s[counter] != 's'
          && s[counter] != 'S' && s[counter] != 'b'
          && s[counter] != 'x' && s[counter] != 'X'
          && s[counter] != 'o' && s[counter] != 'u'
          && s[counter] != 'z' && s[counter] != '%'))
    {
      write(1, " ", 1);
      data += 1;
    }
  return (data);
}

int     my_display(int counter, char *s, va_list tmp)
{
  char  *res;
  int   data;

  data = 0;
  res = malloc(50 * sizeof(char));
  res = my_condif2(counter, s, res);
  while (s[counter] >= '0' && s[counter] <= '9')
    {
      counter++;
      data--;
    }
  res = my_condif(counter, s, tmp, res);
  data = my_calc_data(s, res, counter, data);
  if (s[counter] == 'p')
    {
      data += 2;
      res = hexa(va_arg(tmp, unsigned long int), 16, "0123456789abcdef");
      write(1, "0x", 2);
    }
  my_putstr(res);
  return (my_strlen(res) + data);
}

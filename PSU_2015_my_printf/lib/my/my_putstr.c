/*
** my_putstr.c for my_putstr in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 12:32:59 2015 maxime leroy
** Last update Thu Nov 12 22:06:33 2015 leroy_0
*/

#include "../../include/my.h"

int	my_putstr(char *str)
{
  int z;

  z = 0;
  while (str[z] != '\0')
      {
	my_putchar(str[z]);
	z = z + 1;
      }
  return (0);
}

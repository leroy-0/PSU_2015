/*
** my_putstr.c for my_putstr in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 12:32:59 2015 maxime leroy
** Last update Tue Mar 15 12:54:24 2016 Tekm
*/

#include "../include/my.h"

void	my_putstr(char *str)
{
  int z;

  z = 0;
  while (str[z] != '\0')
    my_putchar(str[z++]);
}

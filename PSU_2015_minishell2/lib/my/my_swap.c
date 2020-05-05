/*
** my_swap.c for my_swap in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 11:08:24 2015 maxime leroy
** Last update Thu Apr 21 09:51:55 2016 leroy_0
*/

#include "my.h"

int	my_swap(int *a, int *b)
{
  int z;

  z = *a;
  *a = *b;
  *b = z;
  return (0);
}

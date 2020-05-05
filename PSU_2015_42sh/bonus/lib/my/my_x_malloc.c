/*
** my_x_malloc.c for my_x_malloc in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:54:45 2016 leroy_0
** Last update Sun Jun  5 17:54:48 2016 leroy_0
*/

#include <stdlib.h>
#include "my.h"

void		*my_x_malloc(size_t size)
{
  void		*p;

  p = malloc(size);
  if (p == 0)
    {
      my_putstr("Error : Malloc failed, now exiting\n");
      exit(0);
    }
  return (p);
}

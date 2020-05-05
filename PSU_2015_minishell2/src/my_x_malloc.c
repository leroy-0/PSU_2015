/*
** my_x_malloc.c for my_x_malloc in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:04:27 2016 leroy_0
** Last update Thu Apr 21 10:04:35 2016 leroy_0
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

void		*my_x_malloc(int size)
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

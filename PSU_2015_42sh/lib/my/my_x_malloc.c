/*
** my_x_malloc.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/my_x_malloc.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:10:50 2016 Arthur KLEIN
** Last update Sat Jun 04 19:10:50 2016 Arthur KLEIN
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

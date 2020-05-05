/*
** my_put_nbr.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/my_put_nbr.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:10:39 2016 Arthur KLEIN
** Last update Sat Jun 04 19:10:39 2016 Arthur KLEIN
*/

#include <unistd.h>
#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -1 * nb;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar((nb % 10) + 48);
  return (nb);
}

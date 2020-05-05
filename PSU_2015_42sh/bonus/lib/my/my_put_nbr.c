/*
** my_put_nbr.c for my_put_nbr in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:55:22 2016 leroy_0
** Last update Sun Jun  5 17:55:26 2016 leroy_0
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

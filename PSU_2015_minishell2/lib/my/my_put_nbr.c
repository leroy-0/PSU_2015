/*
** my_put_nbr.c for my_putnbr in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:37:14 2016 leroy_0
** Last update Thu Apr 21 09:37:29 2016 leroy_0
*/

#include "my.h"

int     my_put_nbr(int nb)
{
  int   a;

  a = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb >= 10)
    {
      a = (nb % 10);
      nb = (nb - a) / 10;
      my_put_nbr(nb);
      my_putchar('0' + a);
    }
  else
    my_putchar('0' + nb % 10);
  return (0);
}

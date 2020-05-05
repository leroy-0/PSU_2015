/*
** my_putnbr.c for my_putnbr in /home/leroy_0/rendu/Piscine_C_J03
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Oct  2 20:29:21 2015 maxime leroy
** Last update Mon Nov  9 16:15:14 2015 leroy_0
*/

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

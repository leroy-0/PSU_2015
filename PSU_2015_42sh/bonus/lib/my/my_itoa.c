/*
** my_itoa.c for my_itoa in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Fri Jun  3 18:56:47 2016 bruere_s
** Last update Sun Jun  5 23:28:46 2016 longle_h
*/

#include	<stdlib.h>
#include	"my.h"

int		my_intlen(long int nbr)
{
  int		i;

  i = 0;
  while (nbr != 0)
    {
      nbr = nbr / 10;
      i++;
    }
  return (i);
}

char		*my_itoa(int x)
{
  int		i;
  long int	n;
  char		*buf;

  n = x;
  i = my_intlen(n);
  buf = my_x_malloc(sizeof(char) * (i + 1));
  buf[i] = '\0';
  i--;
  while (i >= 0)
    {
      buf[i] = n % 10 + '0';
      n = n / 10;
      i--;
    }
  return (buf);
}

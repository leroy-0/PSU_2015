/*
** my_itoa.c for my_itoa in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Fri Jun  3 18:56:47 2016 bruere_s
** Last update Sun Jun  5 20:21:54 2016 bruere_s
*/

#include	<stdlib.h>
#include	<unistd.h>

static void	my_putstr(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    {
      write(2, &s[i], 1);
      i++;
    }
}

static void	*my_x_malloc(size_t size)
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

/*
** my_puterr.c for my_puterr in /home/bruere_s/Projet/PSU_2015_minitalk/lib/my
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Mon Feb  1 23:35:47 2016 Sebastien BRUERE
** Last update Sun Jun  5 21:28:40 2016 bruere_s
*/

#include	<unistd.h>

void		my_putcerr(char c)
{
  write(2, &c, 1);
}

char		**my_puterr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putcerr(str[i]);
      i++;
    }
  return (NULL);
}

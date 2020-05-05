/*
** my_strcut.c for my_strcut in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Thu Jun  2 21:40:51 2016 bruere_s
** Last update Sun Jun  5 20:30:24 2016 bruere_s
*/

#include	<unistd.h>
#include	<stdlib.h>

void		*my_x_malloc(size_t size)
{
  void		*p;

  p = malloc(size);
  if (p == 0)
    {
      write(2, "Error : Malloc failed, now exiting\n", 37);
      exit(0);
    }
  return (p);
}

char		*my_str_cut(char *s, int j)
{
  char		*s2;
  int		i;

  i = 0;
  while (s[i] != '\0')
    i++;
  s2 = my_x_malloc(sizeof(char) * ((i - j) + 1));
  i = 0;
  while (s[j] != '\0')
    {
      s2[i] = s[j];
      i++;
      j++;
    }
  s2[i] = '\0';
  return (s2);
}

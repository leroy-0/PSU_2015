/*
** epur_quote.c for epur_quote in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Fri Jun  3 15:04:16 2016 bruere_s
** Last update Sun Jun  5 20:26:13 2016 bruere_s
*/

#include	<stdlib.h>
#include	<unistd.h>

static void	*my_x_malloc(size_t size)
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

static int	nb_quote(char *s, int *i)
{
  int		nb;

  nb = 0;
  while (s && s[*i] && s[*i] != '\0')
    {
      if (s[*i] == '"')
	nb++;
      (*i)++;
    }
  if (nb == 0)
    return (-1);
  if (nb % 2 != 0)
    return (-2);
  return (nb);
}

char		*epur_quote(char *s)
{
  int		i;
  int		j;
  int		nb;
  char		*tmp;

  i = 0;
  j = 0;
  if ((nb = nb_quote(s, &i)) == -1)
    return (s);
  else if (nb == -2)
    return (NULL);
  tmp = my_x_malloc(sizeof(char) * ((i - nb) + 2));
  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] != '"')
	{
	  tmp[j] = s[i];
	  j++;
	}
      i++;
    }
  tmp[j] = '\0';
  return (tmp);
}

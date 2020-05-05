/*
** epur_virgule.c for epur_virgule in /home/bruere_s/Projet/PSU_2015_42sh/lib/my
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Mon May 30 20:54:28 2016 bruere_s
** Last update Sun Jun  5 21:31:25 2016 bruere_s
*/

#include	<stdlib.h>
#include	<unistd.h>

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

static int	my_strlen(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

static char		*fill_buf(char *buf, char *str, int *i, int *j)
{
  buf[(*j)++] = str[(*i)++];
  if (str[*i] == ';')
    {
      buf[(*j)] = ';';
      (*j)++;
      while (str[*i] == ';' || str[*i] == ' ')
	(*i)++;
      buf[(*j)] = ' ';
      (*j)++;
    }
  return (buf);
}

static char	*epur_end(char *s)
{
  int		i;

  i = my_strlen(s);
  if (i != 0)
    {
      if (s[i - 1] == ';')
	s[i - 1] = '\0';
    }
  return (s);
}

char		*epur_virgule(char *str)
{
  int		i;
  int		j;
  char		*buf;

  i = 0;
  j = 0;
  buf = my_x_malloc(sizeof(buf) * (my_strlen(str) + 1000));
  while (str[i] == ';' || str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] && str[i] != '\0')
    buf = fill_buf(buf, str, &i, &j);
  buf[j] = '\0';
  buf = epur_end(buf);
  free(str);
  return (buf);
}

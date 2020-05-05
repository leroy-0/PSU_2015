/*
** epur_virgule.c for epur_virgule in /home/bruere_s/Projet/PSU_2015_42sh/lib/my
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Mon May 30 20:54:28 2016 bruere_s
** Last update Sun Jun  5 23:29:21 2016 longle_h
*/

#include	<stdlib.h>
#include	"my.h"

static char		*fill_buf(char *buf, char *str, int *i, int *j)
{
  buf[(*j)++] = str[(*i)++];
  if (str[*i] == ';')
    {
      buf[(*j)++] = ';';
      while (str[*i] == ';' || str[*i] == ' ')
	(*i)++;
      buf[(*j)++] = ' ';
    }
  return (buf);
}

static char		*epur_end(char *s)
{
  int			i;

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
  buf = my_x_malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i] == ';' || str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] && str[i] != '\0')
    buf = fill_buf(buf, str, &i, &j);
  buf[j] = '\0';
  buf = epur_end(buf);
  free(str);
  return (buf);
}

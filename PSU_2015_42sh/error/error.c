/*
** error.c for 42sh in /home/klein_h/Documents/rendu/PSU_2015_42sh/error
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Apr 28 15:04:37 2016 klein_h
** Last update Sun Jun  5 21:16:56 2016 bruere_s
*/

#include	<unistd.h>
#include	"my.h"

char		*display_error_local_variable(char *s)
{
  my_puterr(s);
  my_puterr(": Undefined variable.\n");
  return (NULL);
}

char		**display_error_local_variable_tab(char *s)
{
  my_puterr(s);
  my_puterr(": Undefined variable.\n");
  return (NULL);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab && tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
}

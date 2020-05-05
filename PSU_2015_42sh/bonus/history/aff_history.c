/*
** aff_history.c for aff_history in /home/longle_h/rendu/PSU_2015_42sh/bonus/history
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Sat Jun  4 17:50:50 2016 longle_h
** Last update Sat Jun  4 19:20:50 2016 bruere_s
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"history.h"
#include	"built_in.h"

char		**aff_history(char *str, char **env)
{
  char		**hist;
  int		i;

  (void)str;
  (void)env;
  i = 0;
  if ((hist = gimme_hist()) == NULL)
    return (NULL);
  else
    {
      while (hist[i] != NULL)
	{
	  printf("  %i\t%s\n", i + 1, hist[i]);
	  i++;
	}
      free_tab(hist);
    }
  return (env);
}

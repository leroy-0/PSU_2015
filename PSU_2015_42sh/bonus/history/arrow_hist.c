/*
** arrow_hist.c for arrow_hist in /home/longle_h/rendu/PSU_2015_42sh/bonus/history
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Sat Jun  4 16:14:24 2016 longle_h
** Last update Mon Jun  6 00:14:14 2016 longle_h
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<sys/ioctl.h>
#include	"history.h"
#include	"built_in.h"
#include	"bonus.h"
#include	"my.h"

void			move_cursor(char **env, char **hist, int *i)
{
  struct winsize	w;
  int			len;
  int			col;
  int			cpt;

  cpt = 0;
  col = 0;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  len = my_strlen(hist[*i - 1])
    + my_strlen(my_search_env("USER", env))
    + my_strlen(my_search_env("PWD", env)) + 3;
  if (len > w.ws_col && w.ws_col > 0)
    col = len / w.ws_col;
  while (cpt < col)
    {
      action_key("dl");
      action_key("up");
      cpt++;
    }
}

char			*go_down(char **hist, int *i, char **env)
{
  static int		tmpi = 0;

  tmpi = *i;
  if (*i < (tablen(hist)))
    (*i) += 1;
  if (*i > 0 && hist && hist[*i] && hist[*i - 1] && *i != tmpi)
    move_cursor(env, hist, i);
  if (hist != NULL && hist[(*i)] != NULL)
    {
      action_key("dl");
      display_prompt(env);
      write(0, hist[(*i)], strlen(hist[(*i)]));
      return (hist[(*i)]);
    }
  action_key("dl");
  display_prompt(env);
  return (strdup("\0"));
}

void			move_cursor_up(char **env, char **hist, int *i)
{
  struct winsize	w;
  int			len;
  int			col;
  int			cpt;

  cpt = 0;
  col = 0;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  if (hist[*i] && hist[*i + 1])
    {
      len = my_strlen(hist[*i + 1])
	+ my_strlen(my_search_env("USER", env))
	+ my_strlen(my_search_env("PWD", env)) + 3;
      if (len > w.ws_col && w.ws_col > 0)
	col = len / w.ws_col;
      while (cpt < col)
	{
	  action_key("dl");
	  action_key("up");
	  cpt++;
	}
    }
}

char			*go_up(char **hist, int *i, char **env)
{
  if ((*i) > 0)
    (*i) -= 1;
  if (hist != NULL && hist[(*i)] != NULL )
    {
      move_cursor_up(env, hist, i);
      action_key("dl");
      display_prompt(env);
      write(0, hist[(*i)], strlen(hist[(*i)]));
      return (hist[(*i)]);
    }
  action_key("dl");
  display_prompt(env);
  return (strdup("\0"));
}

char		*move_hist(char todo, char **env)
{
  static int	i = -1;
  char		**hist;

  if ((hist = gimme_hist()) == NULL)
    {
      display_prompt(env);
      return (strdup("\0"));
    }
  if (i == -1)
    i = tablen(hist);
  if (todo == 'u')
    return (go_up(hist, &i, env));
  else if (todo == 'd')
    return (go_down(hist, &i, env));
  else if (todo == 'c')
    i = -1;
  return (strdup("\0"));
}

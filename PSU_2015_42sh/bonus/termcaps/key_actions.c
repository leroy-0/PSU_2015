/*
** key_actions.c for key_actions in /home/leroy_0/tek1/PSU_2015_42sh/bonus/termcaps
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jun  2 23:56:32 2016 leroy_0
** Last update Sun Jun  5 21:37:55 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <signal.h>
#include "built_in.h"
#include "bonus.h"
#include "my.h"

char		*my_backspace(char *str, t_cursor *cursor, char **env)
{
  (void)env;
  if (cursor->x != 0)
    {
      cursor->x--;
      str = delete_char(str, cursor->x);
      action_key("le");
      action_key("dm");
      action_key("dc");
      action_key("ed");
    }
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*place_my_char(t_cursor *cursor, char *str, int ch)
{
  char		*tmp;

  if (!str)
    str = strdup("\0");
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
    return (NULL);
  tmp = get_current_str(cursor, str, ch, tmp);
  return (tmp);
}

char		*my_print_char(t_cursor *cursor, char *str, int ch, char **env)
{
  static int	pass = 0;
  int		cpt;

  action_key("dl");
  action_key("cr");
  display_prompt(env);
  str = place_my_char(cursor, str, ch);
  cpt = my_strlen(str);
  if (ch > 127 && pass == 0)
    {
      cursor->x++;
      pass = 1;
    }
  else if (ch <= 127)
    cursor->x++;
  else
    pass = 0;
  while (cpt > cursor->x)
    {
      action_key("le");
      cpt--;
    }
  return (str);
}

char		*check_fnc_ptrs(t_ptrs *ptrs, t_cursor *cursor,
				char **env, char *str)
{
  int		cpt;

  cpt = 0;
  while (ptrs[cpt].nb != 0)
    {
      if (ptrs[cpt].nb == cursor->ch)
	{
	  if ((str = ptrs[cpt].ptr(str, cursor, env)) == NULL)
	    my_exit(NULL, env);
	  cursor->pass = 1;
	  return (str);
	}
      cpt++;
    }
  cursor->pass = 0;
  return (str);
}

char		*my_getstr(char **env)
{
  static char	**paths = NULL;
  t_cursor	cursor;
  t_ptrs	*ptrs;
  char		*str;

  str = NULL;
  if (!paths)
    paths = save_paths(env);
  ptrs = init_values(&cursor, paths);
  cursor.ch = '0';
  while (1)
    {
      if ((cursor.ch = getchar()) == EOF)
      	return (NULL);
      if (cursor.ch == 4)
	return (NULL);
      else if (cursor.ch == 10)
	return (my_return_to_line(str, &cursor, env));
      str = check_fnc_ptrs(ptrs, &cursor, env, str);
      if (cursor.pass == 0 && cursor.ch <= 127 && cursor.ch > 31)
	{
	  if ((str = my_print_char(&cursor, str, cursor.ch, env)) == NULL)
	    return (NULL);
	}
      else
	cursor.pass = 0;
    }
}

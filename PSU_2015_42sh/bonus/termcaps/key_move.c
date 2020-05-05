/*
** key_move.c for key_move in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:01:53 2016 leroy_0
** Last update Sun Jun  5 20:03:35 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <signal.h>
#include "history.h"
#include "bonus.h"
#include "my.h"

char		*my_return_to_line(char *str, t_cursor *cursor, char **env)
{
  (void)env;
  cursor->x = 0;
  my_putchar('\n');
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*my_ctrl_l(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  cpt = my_strlen(str);
  action_key("cr");
  action_key("cl");
  display_prompt(env);
  if (str)
    my_putstr(str);
  while (cpt > cursor->x)
    {
      action_key("le");
      cpt--;
    }
  if (str == NULL)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*my_move_cursor(char *str, t_cursor *cursor, char **env)
{
  char		buf[2];

  (void)env;
  buf[0] = getchar();
  buf[1] = getchar();
  if (str == NULL)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  else if (which_action("kcub1", buf[1]) == 0)
    my_cursor_left(cursor);
  else if (which_action("kcuf1", buf[1]) == 0)
    my_cursor_right(cursor, str);
  else if (which_action("kcuu1", buf[1]) == 0)
    str = my_cursor_up(str, cursor, env);
  else if (which_action("kcud1", buf[1]) == 0)
    str = my_cursor_down(str, cursor, env);
  return (str);
}

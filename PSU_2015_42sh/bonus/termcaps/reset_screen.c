/*
** reset_screen.c for init_and_reset in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sat Jun  4 13:21:43 2016 leroy_0
** Last update Sun Jun  5 17:48:34 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include "built_in.h"
#include "bonus.h"
#include "my.h"

int			reset_screen(char **env)
{
  struct termios	term;
  char			*name_term;

  if ((name_term = my_search_env("TERM", env)) == NULL)
    return (1);
  if (tgetent(NULL, name_term) <= 0)
    return (1);
  if (tcgetattr(0, &term) == -1)
    return (1);
  term.c_lflag = (ECHO | ECHONL | ICANON | ISIG | IEXTEN);
  if (tcsetattr(0, 0, &term) == -1)
    return (1);
  return (0);
}

int			init_that_term(char **env)
{
  struct termios	term;
  char			*name_term;

  if ((name_term = my_search_env("TERM", env)) == NULL)
    return (1);
  if (tgetent(NULL, name_term) <= 0)
    {
      my_puterr("Error : Cannot find a valid term\n");
      return (1);
    }
  if (tcgetattr(0, &term) == -1)
    return (1);
  term.c_lflag &= ~(ICANON);
  term.c_lflag &= ~(ECHO);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &term) == -1)
    return (1);
  return (0);
}

int			init_term(int reset, char **env)
{
  if (reset == 0)
    {
      if (init_that_term(env) == 1)
	return (1);
    }
  else
    {
      if (reset_screen(env) == 1)
	{
	  my_puterr("Error : Cannot find a valid term\n");
	  return (1);
	}
    }
  return (0);
}

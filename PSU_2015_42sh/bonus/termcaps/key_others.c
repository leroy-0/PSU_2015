/*
** key_others.c for key_other in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:00:00 2016 leroy_0
** Last update Sun Jun  5 21:21:08 2016 leroy_0
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
#include "bonus.h"
#include "my.h"

void		action_key(char *str)
{
  char		*str_key;

  str_key = tgetstr(str, NULL);
  write(1, str_key, my_strlen(str_key));
}

char		*save_str(char *str, int ch)
{
  char		*tmp;
  int		where;

  if (!str)
    {
      if ((str = malloc(sizeof(char) * 2)) == NULL)
	return (NULL);
      str[0] = ch;
      str[1] = '\0';
    }
  else
    {
      if ((tmp = malloc(sizeof(char) * my_strlen(str) + 2)) == NULL)
	return (NULL);
      strcpy(tmp, str);
      where = my_strlen(str);
      tmp[where] = ch;
      tmp[where + 1] = '\0';
      if ((str = malloc(sizeof(char) * my_strlen(tmp) + 1)) == NULL)
	return (NULL);
      strcpy(str, tmp);
    }
  return (str);
}

int		which_action(char *str, char ch)
{
  char		*esc_key;
  int		cpt;

  esc_key = NULL;
  if ((esc_key = tigetstr(str)) == NULL)
    return (1);
  if (esc_key)
    {
      cpt = strlen(esc_key) - 1;
      if (esc_key[cpt] == ch)
	return (0);
    }
  return (1);
}

char		*delete_char(char *str, int where)
{
  char		*tmp;
  int		cpt_tmp;
  int		cpt;

  cpt = 0;
  cpt_tmp = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  if (str[cpt] && str[cpt + 1] && cpt == where && str[cpt] < 0)
    cpt += 2;
  else if (str && str[cpt] && cpt == where)
    cpt++;
  while (str && str[cpt] && cpt != where)
    {
      tmp[cpt_tmp] = str[cpt];
      cpt_tmp++;
      cpt++;
      if (str[cpt] && str[cpt + 1] && cpt == where && str[cpt] < 0)
	cpt += 2;
      else if (str[cpt] && cpt == where)
	cpt++;
    }
  tmp[cpt_tmp] = '\0';
  free(str);
  return (tmp);
}

char		*my_ctrl_c(char *str, t_cursor *cursor, char **env)
{
  (void)cursor;
  (void)env;
  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  my_putchar('\n');
  cursor->x = 0;
  display_prompt(env);
  return (str);
}

/*
** key_direction.c for key_direction in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:03:16 2016 leroy_0
** Last update Sun Jun  5 20:20:21 2016 leroy_0
*/

#include	"history.h"
#include	"bonus.h"
#include	"my.h"

void		my_cursor_left(t_cursor *cursor)
{
  if (cursor->x != 0)
    {
      action_key("le");
      cursor->x--;
    }
}

void		my_cursor_right(t_cursor *cursor, char *str)
{
  if (my_strlen(str) != cursor->x)
    {
      cursor->x++;
      action_key("nd");
    }
}

char		*my_cursor_up(char *str, t_cursor *cursor, char **env)
{
  action_key("li");
  action_key("dl");
  action_key("cr");
  str = move_hist('u', env);
  cursor->x = my_strlen(str);
  return (str);
}

char		*my_cursor_down(char *str, t_cursor *cursor, char **env)
{
  action_key("dl");
  action_key("cr");
  str = move_hist('d', env);
  cursor->x = my_strlen(str);
  return (str);
}

char		*get_current_str(t_cursor *cursor, char *str, int ch, char *tmp)
{
  int		cpt;
  int		cpt_tmp;

  cpt = 0;
  cpt_tmp = 0;
  while (str && cpt_tmp < my_strlen(str) + 1)
    {
      if (cursor->x != cpt_tmp)
	{
	  tmp[cpt_tmp] = str[cpt];
	  my_putchar(tmp[cpt_tmp]);
	  cpt++;
	}
      else if (cursor->x == cpt_tmp)
	{
	  tmp[cpt_tmp] = ch;
	  my_putchar(ch);
	}
      cpt_tmp++;
    }
  tmp[cpt_tmp] = '\0';
  return (tmp);
}

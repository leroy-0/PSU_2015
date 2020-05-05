/*
** key_ctrl_w.c for key_ctrl_w in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:35:40 2016 leroy_0
** Last update Sun Jun  5 18:09:53 2016 leroy_0
*/

#include	"bonus.h"
#include	"my.h"

char		*do_ctrl_w(char *str, t_cursor *cursor, int cpt)
{
  while (str && cpt > 0 && str[cpt] && str[cpt] == ' ')
    {
      str = delete_char(str, cpt);
      action_key("le");
      action_key("dc");
      cursor->x--;
      cpt--;
    }
  while (str && cpt >= 0 && str[cpt] && str[cpt] != ' ')
    {
      str = delete_char(str, cpt);
      action_key("le");
      action_key("dc");
      cursor->x--;
      cpt--;
    }
  return (str);
}

char		*my_ctrl_w(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  (void)env;
  if (cursor->x != 0)
    cpt = cursor->x - 1;
  else
    cpt = 0;
  str = do_ctrl_w(str, cursor, cpt);
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

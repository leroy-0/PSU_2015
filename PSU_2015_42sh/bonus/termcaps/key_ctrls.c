/*
** key_ctrls.c for key_ctrls in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sat Jun  4 18:52:37 2016 leroy_0
** Last update Sun Jun  5 18:09:14 2016 leroy_0
*/

#include "bonus.h"
#include "my.h"

char		*my_ctrl_a(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  (void)env;
  (void)str;
  cpt = cursor->x;
  cursor->x = 0;
  while (cpt > cursor->x)
    {
      action_key("le");
      cpt--;
    }
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*my_ctrl_e(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  (void)env;
  cpt = cursor->x;
  if (str)
    cursor->x = my_strlen(str);
  else
    cursor->x = 0;
  while (cpt < cursor->x)
    {
      action_key("nd");
      cpt++;
    }
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*my_ctrl_u(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  (void)env;
  cpt = cursor->x;
  cursor->x = 0;
  while (cpt > cursor->x)
    {
      str = delete_char(str, cpt - 1);
      action_key("le");
      action_key("dc");
      cpt--;
    }
  if (!str)
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
    }
  return (str);
}

char		*my_ctrl_k(char *str, t_cursor *cursor, char **env)
{
  int		cpt;

  (void)env;
  cpt = 0;
  if (str)
    cpt = my_strlen(str) - 1;
  else
    {
      if ((str = malloc(sizeof(char) * 1)) == NULL)
	return (NULL);
      str[0] = '\0';
      return (str);
    }
  while (str && cpt >= 0 && str[cpt] && cpt >= cursor->x)
    {
      str = delete_char(str, cpt);
      action_key("dc");
      cpt--;
    }
  return (str);
}

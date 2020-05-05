/*
** main2.c for mysh in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:57:42 2016 leroy_0
** Last update Thu Apr 21 10:04:01 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "structure.h"

void		my_ctrlc()
{
  signal(SIGINT, my_ctrlc);
  my_putstr("\n$> ");
}

int		check_line(char *str)
{
  int			cpt;

  cpt = 0;
  if (str && my_strlen(str) == 1 && str[0] == ';')
    return (1);
  if (str && my_strlen(str) == 1 && str[0] == '|')
    return (2);
  if (!str)
    return (10);
  while (str[cpt])
    {
      if (str[cpt] == ';' && str[cpt + 1] == ';')
	return (1);
      if (str[cpt] == '|' && str[cpt + 1] == '|')
	return (2);
      else if (str[cpt] == '|' && str[cpt + 1] != '|')
	return (3);
      else if (str[cpt] == '>' || str[cpt] == '<')
	return (4);
      cpt++;
    }
  return (0);
}

char		*my_minish_execute(t_struct_d *data, char *str)
{
  char		*env;

  if (str && str[0] == '\0')
    return ("\0");
  if (str)
    {
      str = epur_str(str);
      env = my_getpath(data->tmpenv, "PATH");
      my_get_envtab(data, env);
      if (my_options(data, str) == -1)
	{
	  my_putstr(data->args[0]);
	  my_putstr(" : Expression Syntax.\n");
	}
      free(str);
      return ("\0");
    }
  return (NULL);
}

char		*get_command(char *str, int where, int cpt)
{
  char		*tmp;
  int		t_cpt;

  t_cpt = 0;
  tmp = my_x_malloc(sizeof(char) * where + 1);
  if (cpt == where)
    {
      free(tmp);
      return (NULL);
    }
  while (cpt < where)
    {
      tmp[t_cpt] = str[cpt];
      t_cpt++;
      cpt++;
    }
  tmp[t_cpt] = '\0';
  return (tmp);
}

int			check_pipes(char *tmp)
{
  int		cpt;

  cpt = 0;
  if (!tmp)
    return (0);
  if (tmp[0] == '|')
    return (1);
  while (tmp && tmp[cpt])
    {
      if (tmp[cpt] == '|' && tmp[cpt + 1] == ' ' && tmp[cpt + 2] == '|')
	return (1);
      if (tmp[cpt] == '|' && tmp[cpt + 1] == '\0')
	return (1);
      if (tmp[cpt] == '|' && tmp[cpt + 1] == ' ' && tmp[cpt + 2] == '\0')
	return (1);
      cpt++;
    }
  return (0);
}

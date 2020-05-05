/*
** main.c for mysh in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:57:11 2016 leroy_0
** Last update Thu Apr 21 10:41:39 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "structure.h"

void            my_cdopt(t_struct_d *data, char *str)
{
  my_setenvir(data, str, "OLDPWD", my_getpath(data->tmpenv, "PWD"));
  if (data->args[1] && data->args[1][0] == '-'
      && data->args[1][1] == '\0')
    chdir(my_getpath(data->tmpenv, "OLDPWD"));
  else if (data->args[1])
    chdir(data->args[1]);
  else
    chdir(my_getpath(data->tmpenv, "HOME"));
}

char		*get_that_cmd(t_struct_d *data, char *str, int cpt, int savecpt)
{
  char			*tmp;

  tmp = get_command(str, cpt, savecpt);
  tmp = epur_str(tmp);
  if ((check_line(tmp) == 3 && check_pipes(tmp) == 0)
      || check_line(tmp) == 4)
    {
      my_pipe(data, tmp);
      tmp[0] = '\0';
    }
  else if (check_line(tmp) == 3 && check_pipes(tmp) == 1)
    tmp[0] = '\0';
  return (tmp);
}

char		*check_that_str(t_struct_d *data, char *str)
{
  static int		cpt = 0;
  int			savecpt;

  savecpt = cpt;
  if (cpt > my_strlen(str) || str[cpt] == '\0')
    {
      cpt = 0;
      return (NULL);
    }
  while (str[cpt] && str[cpt] != ';')
    cpt++;
  if (str[cpt] == ';' || str[cpt] == '\0')
    {
      cpt++;
      return (get_that_cmd(data, str, cpt - 1, savecpt));
    }
  return (NULL);
}

void		my_minish(t_struct_d *data)
{
  char		*str;

  signal(SIGINT, my_ctrlc);
  while (1)
    {
      my_putstr("$> ");
      str = get_next_line(0);
      if (str)
	{
	  str = epur_str(str);
	  if ((check_line(str) == 2 || check_pipes(str) == 1)
	      && check_strrandom(str) == 0)
	    my_putstr("Erreur de syntaxe près du symbole attendu '|'\n");
	  else
	    if (str && str[0] != '\0' && check_strrandom(str) == 0)
	      while (my_minish_execute(data, check_that_str(data, str)) != NULL);
	  free(str);
	}
      else
	{
	  my_putchar('\n');
	  exit(1);
	}
    }
}

int		main(int argc, char **argv, char **envp)
{
  t_struct_d	data;

  (void)argv;
  (void)argc;
  my_get_env(&data, envp);
  my_minish(&data);
  return (0);
}

/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Tue Jan 26 01:51:02 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../get_next_line/get_next_line.h"
#include "../include/structure.h"

void		my_ctrlc()
{
  signal(SIGINT, my_ctrlc);
  my_putstr("\n$> ");
}

void		my_minish_execute(t_struct_d *data, char *str)
{
  char		*env;

  env = my_getpath(data->tmpenv, "PATH");
  my_get_envtab(data, env);
  if (my_options(data, str) == -1)
    {
      my_putstr(data->args[0]);
      my_putstr(" : Expression Syntax.\n");
    }
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
	  if (str && str[0] != '\0')
	    my_minish_execute(data, str);
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
  t_struct_d	*data;

  (void)argv;
  (void)argc;
  data = malloc(sizeof(data) * 10);
  my_get_env(data, envp);
  my_minish(data);
  return (0);
}

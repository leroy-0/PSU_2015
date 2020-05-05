/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Tue Jan 26 01:51:18 2016 leroy_0
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

void		my_cdopt(t_struct_d *data, char *str)
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

char		*my_execute(t_struct_d *data, char *str)
{
  if (str == NULL)
    return (NULL);
  if (str[0] == '\0')
    return (str);
  my_get_args(data, str);
  if (data->args && data->args[0][0] == 'c'
      && data->args[0][1] == 'd' && data->args[0][2] == '\0')
    my_cdopt(data, str);
  else
    {
      if (my_find(data, data->args) != -1)
	{
	  data->pid = fork();
	  my_forkit(data, data->tmpenv);
	}
    }
  return (str);
}

void		my_exitopt(t_struct_d *data, int a)
{
  if (data->args[0] && data->args[1] && data->args[1][a] == '\0'
      && (s_cmp(data->args[0], "exit=")) == 1)
    {
      my_putstr(data->args[0]);
      my_putchar('\n');
      if (my_strint(data->args[1]) <= 255 || my_strint(data->args[1]) >= 0)
	exit(my_strint(data->args[1]));
      else
	exit(1);
    }
  else if (data->args[1] == NULL && data->args[0])
    {
      my_putstr(data->args[0]);
      my_putchar('\n');
      exit(0);
    }
}

int		my_check_exit(t_struct_d *data, char *str)
{
  int		a;

  a = 0;
  if (str)
    my_get_args(data, str);
  while (data->args[1] && (data->args[1][a] >= 48 && data->args[1][a] <= 57))
    a++;
  if (data->args[0] && data->args[2] == NULL
      && (s_cmp(data->args[0], "exit=")) == 1)
    my_exitopt(data, a);
  else if (s_cmp(data->args[0], "exit=") == 1)
    return (-1);
  return (0);
}

int		my_options(t_struct_d *data, char *str)
{
  if (my_check_exit(data, str) == -1)
    return (-1);
  if (str && (my_strlen(str) == 3) && str[0] == 'e'
      && str[1] == 'n' && str[2] == 'v')
    my_showenvir(data);
  else if (str && str[0] == 's' && str[1] == 'e' && str[2] == 't'
	   && str[3] == 'e' && str[4] == 'n' && str[5] == 'v')
    {
      my_get_args(data, str);
      if (data->args[1] == NULL && data->args[2] == NULL)
	my_showenvir(data);
      else
	my_setenvir(data, str, data->args[1], data->args[2]);
    }
  else if (str && str[0] == 'u' && str[1] == 'n' && str[2] == 's'
	   && str[3] == 'e' && str[4] == 't' && str[5] == 'e'
	   && str[6] == 'n' && str[7] == 'v')
    my_unsetenvir(data, str);
  else if (my_execute(data, str) == NULL)
    {
      my_putchar('\n');
      exit(1);
    }
  return (0);
}

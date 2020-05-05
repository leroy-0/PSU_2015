/*
** opts.c for mysh in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:56:53 2016 leroy_0
** Last update Thu Apr 21 10:08:23 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "structure.h"
#include "get_next_line.h"

char		*my_execute(t_struct_d *data, char *str)
{
  if (my_find(data, data->args) != -1)
    {
      data->pid = fork();
      my_forkit(data, data->tmpenv);
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
      if (my_strint(data->args[1]) <= 255 && my_strint(data->args[1]) >= 0)
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
  if (data->args && data->args[0]
      && (s_cmp(data->args[0], "exit=")) == 1)
    {
      while (data->args[1]
	     && (data->args[1][a] >= 48 && data->args[1][a] <= 57))
	a++;
      my_exitopt(data, a);
    }
  else if (s_cmp(data->args[0], "exit=") == 1)
    return (-1);
  return (0);
}

int		my_main_opts(t_struct_d *data, char *str)
{
  my_get_args(data, str);
  if (str && my_strncmp(data->args[0], "exit", my_strlen("exit")) == 0)
    {
      if (my_check_exit(data, str) == -1)
	return (-1);
    }
  else if (str && my_strncmp(data->args[0], "env", my_strlen("env")) == 0)
    my_showenvir(data);
  else if (str
	   && my_strncmp(data->args[0], "setenv", my_strlen("setenv")) == 0)
    {
      if (data->args[1] == NULL)
	my_showenvir(data);
      else
	my_setenvir(data, str, data->args[1], data->args[2]);
    }
  else if (str
	   && my_strncmp(data->args[0], "unsetenv", my_strlen("unsetenv")) == 0)
    my_unsetenvir(data, str);
  else if (data->args && my_strncmp(data->args[0], "cd", my_strlen("cd")) == 0)
    my_cdopt(data, str);
  else
    my_execute(data, str);
  return (0);
}

int		my_options(t_struct_d *data, char *str)
{
  if (str == NULL || str[0] == '\0')
    return (-1);
  else
    return (my_main_opts(data, str));
  return (0);
}

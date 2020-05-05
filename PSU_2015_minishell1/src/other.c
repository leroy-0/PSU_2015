/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Fri Jan 29 15:23:49 2016 leroy_0
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

int		my_finder(t_struct_d *data, char **arg)
{
  int		fd;

  fd = -1;
  if (data->args[0] && ((fd = open(data->args[0], O_RDONLY)) != -1))
    {
      data->thisenv = malloc(sizeof(char) * my_strlen(data->args[0]) + 1);
      my_strcpy(data->thisenv, data->args[0]);
    }
  else if (data->args && data->args[0][0] == '.' && data->args[0][1] == '.')
    return (-1);
  else
    fd = my_finder_antes(data, arg, fd);
  return (fd);
}

int		my_find(t_struct_d *data, char **arg)
{
  int		fd;

  fd = my_finder(data, arg);
  if (fd == -1)
    {
      my_putstr(arg[0]);
      my_putstr(" : Unable to find the command\n");
    }
  return (fd);
}

void		my_get_args(t_struct_d *data, char *str)
{
  int			a;
  int			b;

  a = 0;
  b = 0;
  data->nbarg = 0;
  data->args = malloc(sizeof(char *) * my_strlen(str));
  while (str && str[a] != '\0')
    {
      data->args[data->nbarg] = malloc(sizeof(char)*my_strlen(str));
      a = my_whil(data, a, b, str);
      data->nbarg++;
      b = 0;
      if (str[a] != '\0')
	a++;
    }
  data->args[data->nbarg] = NULL;
}

char		**my_get_newenv(t_struct_d *data, int a, int b)
{
  char	**newenv;

  while (data->tmpenv && data->tmpenv[a])
    a++;
  newenv = malloc(sizeof(char *) * a);
  a = 0;
  while (data->tmpenv && data->tmpenv[a])
    {
      newenv[a] = malloc(sizeof(char) * my_strlen(data->tmpenv[a]) + 1);
      if (data->args[1] && s_cmp(data->args[1], data->tmpenv[a]) != 1)
	{
	  my_strcpy(newenv[b], data->tmpenv[a]);
	  b++;
	}
      a++;
    }
  newenv[a - 1] = NULL;
  return (newenv);
}

void		my_unsetenvir(t_struct_d *data, char *str)
{
  char	**newenv;
  int	a;
  int	b;

  a = 0;
  b = 0;
  my_get_args(data, str);
  if (data->args[0] && data->args[1])
    {
      newenv = my_get_newenv(data, a, b);
      data->tmpenv = malloc(sizeof(char *) * 100);
      a = 0;
      while (newenv[a])
	{
	  data->tmpenv[a] = malloc(sizeof(char) * my_strlen(newenv[a]) + 1);
	  my_strcpy(data->tmpenv[a], newenv[a]);
	  a++;
	}
      data->tmpenv[a] = NULL;
    }
}

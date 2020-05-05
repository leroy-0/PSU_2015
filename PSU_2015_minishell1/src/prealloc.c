/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Tue Jan 26 01:51:34 2016 leroy_0
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

void		my_setenvir_antes(t_struct_d *data, char *arg1, char *arg2, int a)
{
  int	b;
  int	c;

  b = 0;
  c = 0;
  data->tmpenv[a] = malloc(sizeof(char) * (my_strlen(arg1)
					   + my_strlen(arg2) + 2));
  while (arg1 && arg1[b])
    {
      data->tmpenv[a][b] = arg1[c];
      b++;
      c++;
    }
  c = 0;
  data->tmpenv[a][b] = '=';
  b++;
  while (arg2 && arg2[c])
    {
      data->tmpenv[a][b] = arg2[c];
      c++;
      b++;
    }
  data->tmpenv[a][b] = '\0';
}

char		**my_other_set(t_struct_d *data, char *arg1, char *arg2)
{
  char **newenv;
  int	a;

  a = 0;
  while (data->tmpenv[a])
    a++;
  newenv = malloc(sizeof(char *) * (a + 1));
  a = 0;
  while (data->tmpenv[a])
    {
      newenv[a] = malloc(sizeof(char) * my_strlen(data->tmpenv[a]) + 1);
      my_strcpy(newenv[a], data->tmpenv[a]);
      a++;
    }
  newenv[a] = malloc(sizeof(char) * my_strlen(arg1) + my_strlen(arg2) + 2);
  if (arg1)
    my_strcpy(newenv[a], arg1);
  my_strcat(newenv[a], "=");
  if (arg2)
    my_strcat(newenv[a], arg2);
  newenv[a + 1] = NULL;
  return (newenv);
}

void		my_final_set(t_struct_d *data, char *arg1, char *arg2, int a)
{
  char	**newenv;
  int		b;

  b = 0;
  a = 0;
  newenv = my_other_set(data, arg1, arg2);
  data->tmpenv = malloc(sizeof(char *) * b);
  a = 0;
  while (newenv[a])
    {
      data->tmpenv[a] = malloc(sizeof(char) * my_strlen(newenv[a]) + 1);
      my_strcpy(data->tmpenv[a], newenv[a]);
      a++;
    }
  data->tmpenv[a] = NULL;
}

int		my_setenvir(t_struct_d *data, char *str, char *arg1, char *arg2)
{
  int	a;

  a = 0;
  while (data->tmpenv[a])
    {
      if (arg1 && s_cmp(arg1, data->tmpenv[a]) == 1)
	{
	  my_setenvir_antes(data, arg1, arg2, a);
	  return (0);
	}
      a++;
    }
  my_get_args(data, str);
  my_final_set(data, arg1, arg2, a);
  return (0);
}

void		my_showenvir(t_struct_d *data)
{
  int		a;

  a = 0;
  while (data->tmpenv[a])
    {
      my_putstr(data->tmpenv[a]);
      my_putchar('\n');
      a++;
    }
}

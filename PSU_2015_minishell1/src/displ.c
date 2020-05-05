/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Tue Jan 26 01:50:35 2016 leroy_0
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

int		my_whil(t_struct_d *data, int a, int b, char *str)
{
  while (str && str[a] != ' ' && str[a] != '\0')
    {
      data->args[data->nbarg][b] = str[a];
      a++;
      b++;
    }
  data->args[data->nbarg][b] = '\0';
  return (a);
}

char		*my_envir(char **envp, int a)
{
  char		*thisenv;
  int	b;
  int	c;

  b = 0;
  c = 0;
  thisenv = malloc(sizeof(char) * my_strlen(envp[a]) - 4);
  while (envp[a][b] != '=' && envp[a][b] != '\0')
    b++;
  if (envp[a][b] != '\0')
    b++;
  while (envp[a][b] != '\0')
    {
      thisenv[c] = envp[a][b];
      b++;
      c++;
    }
  thisenv[c] = '\0';
  return (thisenv);
}

char		*my_getpath(char **envp, char *name)
{
  int	a;

  a = 0;
  while (envp[a])
    {
      if ((s_cmp(name, envp[a])) == 1)
	return (my_envir(envp, a));
      a++;
    }
  return (NULL);
}

void		my_get_envtab(t_struct_d *data, char *env)
{
  int		a;
  int		b;
  int		c;

  a = 0;
  b = 0;
  data->envtab = malloc(sizeof(char *) * my_strlen(env));
  while (env && env[a] != '\0')
    {
      c = 0;
      data->envtab[b] = malloc(sizeof(char) * my_strlen(env));
      while (env[a] != ':' && env[a] != '\0')
	{
	  data->envtab[b][c] = env[a];
	  a++;
	  c++;
	}
      data->envtab[b][c] = '\0';
      if (env[a] != '\0')
	a++;
      b++;
    }
}

int		my_which_find(t_struct_d *data, char **arg, int fd, int b)
{
  char		*strenv;
  int		a;

  a = 0;
  while (fd == -1 && data->envtab[b])
    {
      strenv = malloc(sizeof(char)
		      * (my_strlen(arg[0]) + my_strlen(data->envtab[b])) + 3);
      while (data->envtab && data->envtab[b][a] != '\0')
	{
	  strenv[a] = data->envtab[b][a];
	  a++;
	}
      strenv[a] = '/';
      strenv = my_strcat(strenv, arg[0]);
      fd = open(strenv, O_RDONLY);
      a = 0;
      b++;
    }
  data->thisenv = malloc(sizeof(char) * my_strlen(strenv) + 1);
  my_strcpy(data->thisenv, strenv);
  return (fd);
}

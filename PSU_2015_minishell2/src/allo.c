/*
** mysh.c for mysh in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Thu Apr 21 10:02:57 2016 leroy_0
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
#include "my.h"
#include "get_next_line.h"
#include "structure.h"
#include "mysh.h"

int		s_cmp(char *dest, char *src)
{
  int		a;
  int		b;

  a = 0;
  b = 0;
  while (src && src[a] != '\0' && dest && dest[a] != '\0'
	 && dest[a] == src[a])
    a++;
  while (src && src[b] != '=')
    b++;
  if ((b == my_strlen(dest)) && (src[a] == '='))
    return (1);
  else
    return (0);
}

void		my_get_env(t_struct_d *data, char **envp)
{
  int		a;

  a = 0;
  while (envp[a])
    a++;
  data->tmpenv = my_x_malloc(sizeof(char *) * (a + 1));
  a = 0;
  while (envp[a])
    {
      data->tmpenv[a] = my_x_malloc(sizeof(char) * (my_strlen(envp[a]) + 1));
      my_strcpy(data->tmpenv[a], envp[a]);
      a++;
    }
  data->tmpenv[a] = NULL;
}

void		my_wait_ch()
{
  int		stat;

  wait(&stat);
  if (WIFSIGNALED(stat))
    {
      if (WTERMSIG(stat) == 11)
	my_putstr("Segmentation Fault (core dumped)\n");
      else if (WTERMSIG(stat) == 8)
	my_putstr("Floating point exception (core dumped)\n");
      else
	my_putstr("Processus Killed\n");
    }
  else if (WIFSTOPPED(stat))
    my_putstr("Processus stopped\n");
}

void		my_forkit(t_struct_d *data, char **envp)
{
  if (data->pid == -1)
    {
      my_putstr("Error : Fork failed, now exiting\n");
      exit(1);
    }
  else if (data->pid != 0)
    my_wait_ch();
  else if (data->pid == 0)
    {
      data->args[0] = data->thisenv;
      if (((data->args[0] && (data->args[0][0] == '.'
			      && data->args[0][1] == '/'))
	   || data->args[0][0] == '/'))
	{
	  if (data->args[0][1] != '.')
	    execve(data->thisenv, data->args, envp);
	}
      exit(1);
    }
}

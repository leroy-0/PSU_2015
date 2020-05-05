/*
** my_exec.c for my_exec in /home/leroy_0/rendu/PSU_2015_my_exec
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 14:15:48 2016 leroy_0
** Last update Thu Jan  7 17:23:06 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/my.h"
#include "structure.h"

void		my_padre(t_struct_d *data)
{
  my_putstr("Programm name : ");
  my_putstr(data->filename);
  my_putchar('\n');
  my_putstr("Nb args : ");
  my_put_nbr(data->nbarg);
  my_putchar('\n');
  my_putstr("PID : ");
  my_put_nbr(getpid());
  my_putchar('\n');
  my_putstr("Child PID : ");
  my_put_nbr(data->pid);
  my_putchar('\n');
  wait(0);
  my_putstr("Programm terminated\n");
  my_putstr("Status : OK\n");
}

void		my_show_pid(t_struct_d *data, char **envp)
{
  if (data->pid == -1)
    {
      my_putstr("ERROR");
      exit(1);
    }
  if (data->pid != 0)
    my_padre(data);
  if (data->pid == 0)
    {
      execve(data->filename, data->args, envp);
      exit(1);
    }
}

int		my_whil(t_struct_d *data, int a, int b, char **argv)
{
  while (argv[1][a] != ' ' && argv[1][a] != '\0')
    {
      if (data->nbarg == 0)
	data->filename[b] = argv[1][a];
      data->args[data->nbarg][b] = argv[1][a];
      a++;
      b++;
    }
  data->args[data->nbarg][b] = '\0';
  return (a);
}

void		my_execute(char **argv, char **envp)
{
  t_struct_d		*data;
  int			a;
  int			b;

  a = 0;
  b = 0;
  data = malloc(sizeof(data));
  data->nbarg = 0;
  data->filename = malloc(sizeof(char)*my_strlen(argv[1]));
  data->args = malloc(sizeof(char *)*my_strlen(argv[1]));
  while (argv[1][a] != '\0')
    {
      data->args[data->nbarg] = malloc(sizeof(char)*my_strlen(argv[1]));
      a = my_whil(data, a, b, argv);
      data->nbarg++;
      b = 0;
      if (argv[1][a] != '\0')
	a++;
    }
  data->args[data->nbarg] = NULL;
  data->pid = fork();
  my_show_pid(data, envp);
}

int		main(int argc, char **argv, char **env)
{
  if (argc < 2)
    return (1);
  if (env == NULL || env[0] == NULL)
    {
      write(1, "Error: Cannot be displayed\n", 27);
      return (-1);
    }
  my_execute(argv, env);
  return (0);
}

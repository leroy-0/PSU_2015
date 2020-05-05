/*
** pipe.c for pipe in /home/tekm/tek1/PSU_2015_minishell2
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Wed Mar 16 17:08:02 2016 Tekm
** Last update Thu Mar 17 13:07:08 2016 Tekm
*/

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_struct_d
{
  int		nbarg;
  char		**args;
}		t_struct_d;

int		my_strlen(char *str)
{
  int		cpt;

  cpt = 0;
  while (str && str[cpt])
    cpt++;
  return (cpt);
}

int             my_whil(t_struct_d *data, int a, int b, char *str)
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

char		**my_get_args(char *str)
{
  t_struct_d	*data;
  int                   a;
  int                   b;

  data = malloc(sizeof(*data));
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
  return (data->args);
}

void		end_fork(int cpt_c, int nbpipe, int *fd, int status)
{
  cpt_c = 0;
  while (cpt_c < 2 * nbpipe)
    close(fd[cpt_c++]);
  cpt_c = 0;
  while (cpt_c < nbpipe + 1)
    {
      wait(&status);
      cpt_c++;
    }
}

void		start_fork(int cpt_c, int nbpipe, int *fd)
{
  while (cpt_c < nbpipe)
    {
      if (pipe(fd + cpt_c * 2) < 0)
	{
	  printf("Error: couldn't run pipe properly\n");
	  exit(1);
	}
      cpt_c++;
    }
}

void		run_pid(char ***cmds, int cpt, int *fd, int cpt_d, int cpt_c, int nbpipe)
{
  if(cmds[cpt] && dup2(fd[cpt_d + 1], 1) < 0)
    {
      printf("Error: dup2 failed\n");
      exit(1);
    }
  if (cpt_d != 0 && dup2(fd[cpt_d-2], 0) < 0)
    {
      printf("Error: dup2 failed\n");
      exit(1);
    }
  cpt_c = 0;
  while (cpt_c < 2 * nbpipe)
    close(fd[cpt_c++]);
  if (execvp(cmds[cpt][0], cmds[cpt]) < 0)
    {
      printf("Error\n");
      exit(EXIT_FAILURE);
    }
}

void		run_pipe(char ***cmds, int nbpipe)
{
  int		cpt_d;
  int		cpt;
  int		cpt_c;
  int		status;
  int		fd[2 * nbpipe];
  pid_t		pid;

  cpt_d = 0;
  cpt = 0;
  cpt_c = 0;
  start_fork(cpt_c, nbpipe, fd);
  while (cmds[cpt])
    {
      pid = fork();
      if (pid == 0)
	run_pid(cmds, cpt, fd, cpt_d, cpt_c, nbpipe);
      else if (pid < 0)
	{
	  printf("Error: pid inferior to 0\n");
	  exit(1);
	}
      cpt++;
      cpt_d += 2;
    }
  end_fork(cpt_c, nbpipe, fd, status);
}

char		***get_all_args(int argc, char **argv)
{
  char		***cmds;
  int		cpt;

  cpt = 1;
  cmds = malloc(sizeof(char **) * argc - 1);
  while (cpt < argc)
    {
      cmds[cpt - 1] = my_get_args(argv[cpt]);
      cpt++;
    }
  cmds[cpt] = NULL;
  return (cmds);
}

int		main(int argc, char **argv)
{
  char		***cmds;

  cmds = get_all_args(argc, argv);
  run_pipe(cmds, argc - 2);
  return (0);
}

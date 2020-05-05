/*
** pipe3.c for pipe3 in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:05:56 2016 leroy_0
** Last update Thu Apr 21 10:06:11 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

void		run_child(t_struct_d *data, t_pipe *piper)
{
  dup2(piper->fdin, 0);
  if (piper->cmds[piper->cpt + 1] != NULL)
    dup2(piper->fd[1], 1);
  close(piper->fd[0]);
  my_find(data, piper->cmds[piper->cpt]);
  if (execve(data->thisenv, piper->cmds[piper->cpt], data->tmpenv) < 0)
    {
      my_putstr("Error : execve failed\n");
      exit(1);
    }
}

int		run_father(t_pipe *piper)
{
  close(piper->fd[1]);
  piper->fdin = piper->fd[0];
  return (piper->fdin);
}

void		run_whl_pipe(t_struct_d *data, t_pipe *piper)
{
  pid_t		pid;

  if (pipe(piper->fd) < 0)
    {
      my_putstr("Error : We couldn't run pipe properly\n");
      return;
    }
  if ((pid = fork()) < 0)
    {
      my_putstr("Error: pid inferior to 0\n");
      return;
    }
  else if (pid == 0)
    run_child(data, piper);
  else
    {
      piper->fdin = run_father(piper);
      piper->cpt++;
      if (piper->cmds[piper->cpt])
	run_whl_pipe(data, piper);
      wait(NULL);
    }
}

void		run_pipe(t_struct_d *data, t_pipe *piper)
{
  piper->cpt = 0;
  piper->fdin = 0;
  if ((piper->fd = my_x_malloc(sizeof(int) * 3)) == NULL)
    return ;
  run_whl_pipe(data, piper);
}

char		***get_all_args(t_struct_d *data, int argc, char **argv, int round)
{
  char		***cmds;
  int		cpt;

  cpt = 0;
  cmds = my_x_malloc(sizeof(char **) * (argc + 1));
  while (cpt < argc)
    {
      cmds[cpt] = my_get_args_p(argv[cpt]);
      if (round == 1)
	if (my_find(data, cmds[cpt]) == -1)
	  return (NULL);
      cpt++;
    }
  cmds[cpt] = NULL;
  return (cmds);
}

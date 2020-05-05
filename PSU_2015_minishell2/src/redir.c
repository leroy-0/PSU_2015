/*
** redir.c for redir in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:07:30 2016 leroy_0
** Last update Thu Apr 21 10:45:13 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"
#include "structure.h"
#include "get_next_line.h"

void		run_redir_r(t_struct_d *data, char ***cmds, int out)
{
  if (cmds && cmds[1] && cmds[1][0])
    out = open(cmds[1][0], O_WRONLY | O_TRUNC | O_CREAT,
	       S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
  if (out == -1)
    exit(1);
  dup2(out, 1);
  close(out);
  my_find(data, cmds[0]);
  if (execve(data->thisenv, cmds[0], data->tmpenv) < 0)
    {
      my_putstr("Error : execve failed\n");
      exit(1);
    }
}

void		my_redir_right(t_struct_d *data, char ***cmds)
{
  int	pid;
  int	out;

  (void)data;
  out = 0;
  pid = fork();
  if (pid == 0)
    run_redir_r(data, cmds, out);
  else if (pid < 0)
    {
      my_putstr("Error : fork has failed\n");
      return;
    }
  else
    wait(NULL);
}

void		run_redir_l(t_struct_d *data, char ***cmds, int in)
{
  int	out;

  out = 0;
  in = open(cmds[1][0], O_RDONLY);
  if (in == -1)
    exit(1);
  dup2(in, 0);
  if (cmds && cmds[1] && cmds[1][1]
      && my_strncmp(cmds[1][1], ">", my_strlen(">")) == 0
      && cmds[1][2])
    {
      out = open(cmds[1][2], O_WRONLY | O_TRUNC | O_CREAT,
		 S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
      if (out == -1)
	exit(1);
      dup2(out, 1);
      close(out);
    }
  close(in);
  my_find(data, cmds[0]);
  if (execve(data->thisenv, cmds[0], data->tmpenv) < 0)
    {
      my_putstr("Error : execve failed\n");
      exit(1);
    }
}

void		my_redir_left(t_struct_d *data, char *str, char ***cmds)
{
  int	pid;
  int	in;

  (void)data;
  (void)str;
  in = 0;
  pid = fork();
  if (pid == 0)
    run_redir_l(data, cmds, in);
  else if (pid < 0)
    {
      my_putstr("Error : fork has failed\n");
      return;
    }
  else
    wait(NULL);
}

void		run_redir_rd(t_struct_d *data, char ***cmds, int out)
{
  out = open(cmds[1][0], O_WRONLY | O_APPEND);
  if (out == -1)
    out = open(cmds[1][0], O_WRONLY | O_TRUNC | O_CREAT,
	       S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
  if (out == -1)
    exit(1);
  dup2(out, 1);
  close(out);
  my_find(data, cmds[0]);
  if (execve(data->thisenv, cmds[0], data->tmpenv) < 0)
    {
      my_putstr("Error : execve failed\n");
      exit(1);
    }
}

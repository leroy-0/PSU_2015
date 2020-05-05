/*
** pipe.c for pipe in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:05:17 2016 leroy_0
** Last update Thu Apr 21 10:05:25 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

void		exec_it(t_struct_d *data, t_pipe *piper, int check, char **arg)
{
  if (piper->args[0] == NULL || piper->args[0][0] == '\0')
    {
      if (check == 0 && my_find(data, arg) != -1)
	{
	  if (my_find(data, arg) != -1)
	    piper->cmds = get_all_args(data, 2, arg, 0);
	  else
	    piper->cmds = NULL;
	}
      else
	piper->cmds = get_all_args(data, 2, arg, 0);
    }
  else
    piper->cmds = get_all_args(data, 2, piper->args, 0);
}

char		**get_argument(t_struct_d *data, t_pipe *piper, char **arg)
{
  if (piper->args[piper->cpt])
    piper->cpt++;
  while (piper->args && piper->args[1] && piper->args[1][piper->cpt])
    {
      if (piper->args[1][piper->cpt] == ' ')
	{
	  arg[0][piper->cpt_c] = '\0';
	  arg[2] = NULL;
 	  if ((piper->args[0] == NULL || piper->args[0][0] == '\0')
	      && my_find(data, arg) == -1)
	    {
	      piper->cmds = NULL;
	      return (NULL);
	    }
	  else
	    piper->check = 1;
	}
      arg[0][piper->cpt_c] = piper->args[1][piper->cpt];
      piper->cpt++;
      piper->cpt_c++;
    }
  return (arg);
}

void		get_pipercmd(t_struct_d *data, t_pipe *piper)
{
  char		**arg;

  piper->cpt = 0;
  piper->cpt_c = 0;
  piper->check = 0;
  arg = my_x_malloc(sizeof(char *) * 20);
  arg[0] = my_x_malloc(sizeof(char) * (my_strlen(piper->args[1]) + 1));
  arg[1] = my_x_malloc(sizeof(char) * (my_strlen(piper->args[1]) + 1));
  while (piper->args[1][piper->cpt] && piper->args[1][piper->cpt] != ' ')
    {
      arg[1][piper->cpt] = piper->args[1][piper->cpt];
      piper->cpt++;
    }
  arg[1][piper->cpt] = '\0';
  if ((arg = get_argument(data, piper, arg)) == NULL)
    return;
  arg[0][piper->cpt_c] = '\0';
  arg[2] = NULL;
  exec_it(data, piper, piper->check, arg);
}

void		my_redir_opts(t_struct_d *data, t_pipe *piper, char *str)
{
  if (check_redir(str) == 1)
    {
      piper->args = get_cut_args(piper, str, 2, '>');
      get_pipercmd(data, piper);
      my_redir_right(data, piper->cmds);
    }
  else if (check_redir(str) == 2)
    {
      piper->args = get_cut_args(piper, str, 2, '<');
      piper->cmds = get_all_args(data, 2, piper->args, 0);
      my_redir_left(data, str, piper->cmds);
    }
  else if (check_redir(str) == 3)
    {
      piper->args = get_cut_args(piper, str, 2, '>');
      get_pipercmd(data, piper);
      my_redir_rightdouble(data, piper->cmds);
    }
  else if (check_redir(str) == 4)
    {
      piper->args = get_cut_args(piper, str, 2, '<');
      piper->cmds = get_all_args(data, 2, piper->args, 0);
      my_redir_leftdouble(data, str, piper->cmds);
    }
}

int		my_pipe(t_struct_d *data, char *str)
{
  t_pipe	piper;
  char		*env;

  piper.nbpipe = check_pipe(str);
  env = my_getpath(data->tmpenv, "PATH");
  my_get_envtab(data, env);
  if (check_redir(str) == 0)
    {
      piper.args = get_cut_args(&piper, str, piper.nbpipe + 1, '|');
      piper.cmds = get_all_args(data, piper.nbpipe + 1,
				piper.args, 1);
      if (piper.cmds == NULL)
	return (-1);
      run_pipe(data, &piper);
    }
  else
    my_redir_opts(data, &piper, str);
  return (0);
}

/*
** exec.c for exece in /home/klein_h/Documents/rendu/PSU_2015_42sh/exec
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Apr 28 15:05:18 2016 klein_h
** Last update Sun Jun  5 20:59:32 2016 bruere_s
*/

#include	<unistd.h>
#include	<signal.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	"built_in.h"
#include	"exec.h"
#include	"my.h"

int		write_seg(int i, char *prog)
{
  if (prog)
    {
      if ((WTERMSIG(i) == 11) || (WTERMSIG(i) == 139))
	{
	  write(2, prog, strlen(prog));
	  write(2, ": Segmentation fault\n", 21);
	  return (139);
	}
      else if (WTERMSIG(i) == 8 || WTERMSIG(i) == 136)
	{
	  write(2, prog, strlen(prog));
	  write(2, ": Floating Point exception\n", 27);
	  return (136);
	}
    }
  return (0);
}

static int	exec_child(char *command, char **argv, char **env, int pid)
{
  int		ret;

  (void)pid;
  signal(SIGINT, SIG_DFL);
  if (execve(command, argv, env) == -1)
    {
      ret = 1;
      my_put_not_found(argv[0]);
      exit(1);
    }
  else
    ret = 0;
  signal(SIGINT, SIG_IGN);
  return (ret);
}

char		**put_slash_in_path(char **old_path)
{
  char		**new_path;
  int		i;

  new_path = NULL;
  i = 0;
  new_path = my_x_malloc(sizeof(char *) * (my_tablen(old_path) + 1));
  while (old_path[i] != NULL)
    {
      new_path[i] = my_x_malloc(sizeof(char)
				* (strlen(old_path[i]) + 2));
      new_path[i] = strcpy(new_path[i], old_path[i]);
      if (new_path[i][strlen(old_path[i]) - 1] != '/')
	{

	  new_path[i][strlen(old_path[i])] = '/';
	  new_path[i][strlen(old_path[i]) + 1] = '\0';
	}
      i++;
    }
  new_path[i] = NULL;
  return (new_path);
}

static int	exec_binary(char **argv, char **env, int pid)
{
  char		**path_tab;
  char		*path;

  path = NULL;
  path_tab = NULL;
  if ((path_tab = str_to_wordtab(my_search_env("PATH", env), ':')) == NULL)
    {
      exec_child(argv[0], argv, env, pid);
      exit(1);
    }
  path_tab = put_slash_in_path(path_tab);
  if (argv[0] != NULL)
    path = find_good_path(path_tab, argv[0]);
  if (path == NULL)
    {
      my_put_not_found(argv[0]);
      exit(1);
    }
  else
    return (exec_child(path, argv, env, pid));
  return (0);
}

int		my_simple_exec(char *str, char ***env, int pid, int *res)
{
  t_built	*in;
  int		ret;

  pid = 0;
  in = my_x_malloc(sizeof(t_built) * 7);
  if ((ret = fill_ptr_fnc(in, str, env)) == 2)
    (*res) = exec_binary(str_to_wordtab(str, ' '), *env, pid);
  else if (ret == 1)
    return (1);
  else
    return (0);
  return (*res);
}

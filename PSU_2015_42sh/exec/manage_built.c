/*
** manage_built.c for manage_buit in /home/longle_h/rendu/PSU_2015_42sh/exec
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Fri May  6 16:03:15 2016 longle_h
** Last update Sun Jun  5 21:00:17 2016 bruere_s
*/

#include	<unistd.h>
#include	<string.h>
#include	"exec.h"
#include	"built_in.h"
#include	"my.h"

static int	exec_built(t_built *in, char *str, char ***env)
{
  int		i;
  char		**tab_str;
  char		**tmp;

  i = 0;
  if ((str = epur_quote(str)) == NULL)
  {
    write(2, "Unmatched \".\n", 16);
    return (1);
  }
  tab_str = str_to_wordtab(str, ' ');
  while (in[i].built != NULL)
    {
      if (tab_str[0] && strcmp(tab_str[0], in[i].built) == 0)
	{
	  if ((tmp = in[i].ptr(get_cmd(str), *env)) == NULL)
	    return (1);
	  *env = tmp;
	  return (0);
	}
      i++;
    }
  return (2);
}

static void	free_struct(t_built *in)
{
  int		i;

  i = 0;
  while (in[i].built != NULL)
    free(in[i++].built);
  free(in);
}

int		fill_ptr_fnc(t_built *in, char *str, char ***env)
{
  int		ret;

  in[0].built = strdup("cd");
  in[0].ptr = &(my_cd);
  in[1].built = strdup("env");
  in[1].ptr = &(my_env);
  in[2].built = strdup("setenv");
  in[2].ptr = &(my_setenv);
  in[3].built = strdup("unsetenv");
  in[3].ptr = &(my_unsetenv);
  in[4].built = strdup("exit");
  in[4].ptr = &(my_exit);
  in[5].built = strdup("echo");
  in[5].ptr = &(my_echo);
  in[6].built = NULL;
  if ((ret = exec_built(in, str, env)) == 0)
    {
      free_struct(in);
      return (0);
    }
  free_struct(in);
  if (ret == 1)
    return (1);
  else
    return (2);
}

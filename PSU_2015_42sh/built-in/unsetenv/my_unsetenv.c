/*
** my_unsetenv.c for my_unsetenv in /home/leroy_0/tek1/PSU_2015_42sh/built-in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri May  6 13:02:33 2016 leroy_0
** Last update Sun Jun  5 20:46:47 2016 bruere_s
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"my.h"
#include	"built_in.h"

static int	found_in_env(char **env, char *var)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      if ((strncmp(env[i], var, strlen(var)) == 0)
	  && (env[i][strlen(var)] == '='))
	return (i);
      i++;
    }
  return (-1);
}

static char	**remove_all_env()
{
  char		**tmp;

  tmp = my_x_malloc(sizeof(char *) * 1);
  tmp[0] = NULL;
  return (tmp);
}

static char	**get_new_env(char **env, int stop)
{
  int		i;
  int		j;
  char		**my_env;

  i = 0;
  j = 0;
  while (env[i] != NULL)
    i++;
  my_env = my_x_malloc(sizeof(char *) * i);
  i = 0;
  while (env[i] != NULL)
    {
      if (i == stop)
	i++;
      if (env[i] != NULL)
	{
	  my_env[j] = strdup(env[i]);
	  j++;
	  i++;
	}
    }
  my_env[j] = NULL;
  return (my_env);
}

char		**my_unsetenv(char *look, char **env)
{
  char		**tmp;
  char		**myenv;
  int		i;
  int		var;

  i = 0;
  myenv = NULL;
  if ((tmp = str_to_wordtab(look, ' ')) == NULL)
    return (NULL);
  while (tmp[i] != NULL)
    {
      if (strcmp(tmp[i], "*") == 0)
	myenv = remove_all_env();
      else if (myenv == NULL && ((var = found_in_env(env, tmp[i])) != -1))
	myenv = get_new_env(env, var);
      else if (myenv != NULL && ((var = found_in_env(myenv, tmp[i])) != -1))
	myenv = get_new_env(myenv, var);
      i++;
    }
  return (myenv);
}

/*
** cd.c for cd in /home/leroy_0/tek1/PSU_2015_42sh/built-in/cd
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue May  3 15:19:47 2016 leroy_0
** Last update Wed Jun  1 15:14:07 2016 bruere_s
*/

#include	<unistd.h>
#include	<string.h>
#include	"built_in.h"
#include	"my.h"

static int	my_cd_opts(char ***env, char *str)
{
  if (str && strncmp(str, "-", strlen(str)) == 0)
    {
      if ((*env = my_cd_oldpwd(env)) == NULL)
	return (-1);
    }
  else if (str)
    {
      if ((*env = my_cd_directory(env, str)) == NULL)
	return (-1);
    }
  else
    {
      if ((*env = my_cd_home(env)) == NULL)
	return (-1);
    }
  return (0);
}

char		**my_cd(char *str, char **env)
{
  char		**save;

  save = my_get_env(env);
  if (my_cd_opts(&env, str) == -1)
    {
      env = save;
      return (NULL);
    }
  return (env);
}

/*
** my_setenv_tools.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/built-in/setenv/my_setenv_tools.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:14:01 2016 Arthur KLEIN
** Last update Sun Jun  5 20:58:41 2016 bruere_s
*/

#include	<string.h>
#include	<stdlib.h>
#include	"my.h"
#include	"built_in.h"

static char	**fill_tmp_putenv(char **myenv, char *look, char *s, int i)
{
  char		*tmp;

  tmp = my_x_malloc(sizeof(char) * ((strlen(look) + strlen(s)) + 2));
  tmp = strcpy(tmp, look);
  tmp = strcat(tmp, "=");
  tmp = strcat(tmp, s);
  myenv[i] = my_x_malloc(sizeof(char) * (strlen(tmp) + 1));
  myenv[i] = strcpy(myenv[i], tmp);
  free(tmp);
  return (myenv);

}

char		**my_putenv(char *look, char *s, char **myenv)
{
  int		i;

  i = 0;
  if (look == NULL || s == NULL)
    return (NULL);
  while (myenv && myenv[i] != NULL)
    {
      if (strncmp(look, myenv[i], strlen(look)) == 0
	  && myenv[i][(strlen(look))] == '=')
	return (myenv = fill_tmp_putenv(myenv, look, s, i));
      i++;
    }
  if (myenv[i] == NULL)
    {
      myenv = my_putenvend(look, s, myenv);
      return (myenv);
    }
  return (myenv);
}

static char	*my_copy_searchenv(char **env, char *str, int cpt, int i)
{
  int		cpt_str;

  cpt_str = 0;
  if (env[i][cpt])
    cpt++;
  else
    return (NULL);
  while (env[i][cpt])
    {
      str[cpt_str] = env[i][cpt];
      cpt_str++;
      cpt++;
    }
  str[cpt_str] = '\0';
  return (str);
}

char		*my_search_env(char *str, char **env)
{
  int		cpt;
  int		i;

  i = 0;
  cpt = 0;
  while (env && env[i] != NULL)
    {
      if (my_strcmp(str, env[i]) == 0)
	{
	  str = my_x_malloc(sizeof(char) * (strlen(env[i]) + 1));
	  while (env[i][cpt] && env[i][cpt] != '=')
	    cpt++;
	  return (my_copy_searchenv(env, str, cpt, i));
	}
      i++;
    }
  return (NULL);
}

char		**my_get_env(char **env)
{
  char		**my_env;
  int		i;

  i = 0;
  while (env && env[i] != NULL)
    i++;
  my_env = my_x_malloc(sizeof(char *) * (i + 1));
  i = 0;
  while (env && env[i] != NULL)
    {
      my_env[i] = my_x_malloc(sizeof(char) * (strlen(env[i]) + 1));
      my_env[i] = strcpy(my_env[i], env[i]);
      i++;
    }
  my_env[i] = NULL;
  return (my_env);
}

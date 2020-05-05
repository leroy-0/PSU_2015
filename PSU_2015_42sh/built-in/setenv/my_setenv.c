/*
** my_setenv.c for setenv in /home/leroy_0/tek1/PSU_2015_42sh
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri May  6 12:23:53 2016 leroy_0
** Last update Sun Jun  5 21:29:32 2016 bruere_s
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"built_in.h"
#include	"my.h"

static int	check_error_setenv(char *cmd)
{
  int		i;

  i = 0;
  while (cmd[i] != '\0')
    {
      if (((cmd[i] < 'A' || cmd[i] > 'Z')
	   && (cmd[i] < 'a' || cmd[i] > 'z')) && cmd[i] != '_')
	return (1);
      i++;
    }
  return (0);
}

static char	*fill_look(char *str, int *cpt)
{
  char		*look;

  look = my_x_malloc(sizeof(char) * (strlen(str) + 1));
  while (str && str[*cpt] && str[*cpt] != ' ')
    {
      look[*cpt] = str[*cpt];
      (*cpt)++;
    }
  look[*cpt] = '\0';
  if (str && str[*cpt])
    (*cpt)++;
  return (look);
}

char		**my_putenvend(char *look, char *s, char **myenv)
{
  char		**tmpenv;
  int		i;

  i = 0;
  while (myenv && myenv[i])
    i++;
  tmpenv = my_x_malloc(sizeof(char *) * (i + 2));
  i = 0;
  while (myenv && myenv[i])
    {
      tmpenv[i] = my_x_malloc(sizeof(char) * (strlen(myenv[i]) + 1));
      tmpenv[i] = strcpy(tmpenv[i], myenv[i]);
      i++;
    }
  tmpenv[i] = my_x_malloc(sizeof(char) *
		     (strlen(look) + strlen(s) + 2));
  tmpenv[i] = strcpy(tmpenv[i], look);
  tmpenv[i] = strcat(tmpenv[i], "=");
  tmpenv[i] = strcat(tmpenv[i], s);
  tmpenv[i + 1] = NULL;
  free(myenv);
  return (tmpenv);
}

static char	*fill_tmp(char *str, int *cpt)
{
  char		*tmp;
  int		cpt_tmp;

  cpt_tmp = 0;
  tmp = my_x_malloc(sizeof(char) * (strlen(str) + 1));
  while (str && str[*cpt] && str[*cpt] != ' ')
    {
      tmp[cpt_tmp] = str[*cpt];
      cpt_tmp++;
      (*cpt)++;
    }
  tmp[cpt_tmp] = '\0';
  return (tmp);
}

char		**my_setenv(char *str, char **myenv)
{
  char		*look;
  char		*tmp;
  int		cpt;

  cpt = 0;
  if (str == NULL)
    {
      my_env(NULL, myenv);
      return (myenv);
    }
  look = fill_look(str, &cpt);
  tmp = fill_tmp(str, &cpt);
  if (str[cpt] == ' ')
    return (my_puterr("setenv : Too many arguments\n"));
  else if (check_error_setenv(look) == 1)
    return (my_puterr("setenv: Variable \
name must contain alphanumeric characters.\n"));
  else
    myenv = my_putenv(look, tmp, myenv);
  return (myenv);
}

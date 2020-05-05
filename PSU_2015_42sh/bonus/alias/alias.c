/*
** alias.c for alis in /home/bruere_s/Projet/PSU_2015_42sh/bonus/alias
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 14:28:09 2016 bruere_s
** Last update Sun Jun  5 23:41:02 2016 longle_h
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"history.h"
#include	"my.h"
#include	"alias.h"

static char	*find_name_alias(char *alias)
{
  char		*tmp;
  char		*look;
  int		len;

  len = 0;
  tmp = my_str_cut(alias, 6);
  if ((len = my_strlen_car(tmp, '=')) != -1)
    {
      look = my_x_malloc(sizeof(char) * (len + 1));
      len = 0;
      while (tmp[len] != '=' && tmp[len] != '\0')
	{
	  look[len] = tmp[len];
	  len++;
	}
      look[len] = '\0';
      return (look);
    }
  return (NULL);
}

static char	*find_command_in_alias(char *alias)
{
  int		i;
  int		j;
  char		*tmp;

  i = 0;
  while (alias[i] != '=' && alias[i] != '\0')
    i++;
  if (alias[i] != '\0')
    i++;
  j = i;
  while (alias[i] != '\0')
    i++;
  tmp = my_x_malloc(sizeof(char) * ((i - j) + 1));
  i = j;
  j = 0;
  while (alias[i] != '\0')
    {
      tmp[j] = alias[i];
      j++;
      i++;
    }
  tmp[j] = '\0';
  return (tmp);
}

char		*change_variable_in_str(char *alias, char *s)
{
  char		*tmp;
  char		**cmd;
  int		i;
  int		check;

  i = 0;
  check = 0;
  if ((tmp = find_name_alias(alias)) == NULL)
    return (NULL);
  cmd = str_to_wordtab(s, ' ');
  while (cmd[i] != '\0')
    {
      if (strcmp(cmd[i], tmp) == 0)
	{
	  cmd[i] = find_command_in_alias(alias);
	  check = 1;
	}
      i++;
    }
  if (check == 0)
    return (NULL);
  s = tab_to_str(cmd);
  return (s);
}

char		*change_variable_alias(char **alias, char *s)
{
  char		**tmp;
  char		*str;
  int		i;
  int		j;

  i = 0;
  str = NULL;
  while (alias && alias[i] != NULL)
    {
      j = 0;
      tmp = str_to_wordtab(alias[i], ' ');
      while (tmp[j] != NULL && check_good_alias(alias[i], 0) == 0)
	{
	  if (strcmp("alias", tmp[j]) == 0)
	    {
	      if (change_variable_in_str(alias[i], s) != NULL)
		return (str = change_variable_in_str(alias[i], s));
	    }
	  j++;
	}
      i++;
    }
  if (str != NULL)
    return (str);
  return (s);
}

char		**gimme_alias()
{
  char		**alias;
  int		fd;

  alias = NULL;
  if ((fd = open_file_sh(1, ".42rc")) == -1)
    return (NULL);
  if ((alias = read_tab(fd, alias)) == NULL)
    return (NULL);
  close(fd);
  return (alias);
}

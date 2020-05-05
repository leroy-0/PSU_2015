/*
** find_good_path.c for find_path in /home/longle_h/rendu/PSU_2015_42sh/exec
**
** Made by Henri Longle
** Login   <longle_h@epitech.net>
**
** Started on  Thu May  5 16:21:09 2016 Henri Longle
** Last update Sun Jun  5 23:38:16 2016 longle_h
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	"my.h"
#include	"built_in.h"

int		is_direct_path(char *to_find)
{
  int		i;

  i = 0;
  while (to_find[i] != '\0')
    {
      if (to_find[i] == '/')
	return (0);
      i++;
    }
  return (1);
}

char		*get_cmd(char *str)
{
  char		*tmp;
  int		cpt_tmp;
  int		cpt;

  cpt = 0;
  cpt_tmp = 0;
  tmp = my_x_malloc(sizeof(char) * strlen(str));
  while (str[cpt] != '\0' && str[cpt] != ' ')
    cpt++;
  if (str[cpt])
    cpt++;
  while (str && str[cpt] != '\0')
    {
      tmp[cpt_tmp] = str[cpt];
      cpt_tmp++;
      cpt++;
    }
  tmp[cpt_tmp] = '\0';
  if (tmp[0] == '\0')
    return (NULL);
  return (tmp);
}

char		*find_good_path(char **path, char *to_find)
{
  int		i;
  char		*final_path;

  i = 0;
  final_path = NULL;
  if (to_find == NULL)
    return (NULL);
  if (access(to_find, X_OK) == 0 && (is_direct_path(to_find) == 0))
    return (to_find);
  while (path != NULL && path[i] != NULL && to_find[0] != '.'
	 && to_find[0] != '/')
    {
      final_path = my_x_malloc(sizeof(char)
			       * (strlen(path[i]) * strlen(to_find) + 2));
      final_path = strcpy(final_path, path[i]);
      final_path = strcat(final_path, to_find);
      if (access(final_path, X_OK) == 0)
	return (final_path);
      else
	{
	  i++;
	  free(final_path);
	}
    }
  return (NULL);
}

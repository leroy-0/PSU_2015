/*
** save_paths.c for save_paths in /home/poinss_y/Documents/PSU/PSU_2015_42sh/bonus/auto_complete
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 20:23:43 2016 Yan Poinssot
** Last update Sun Jun  5 23:34:23 2016 longle_h
*/

#include	<stdlib.h>
#include	"my.h"
#include	"built_in.h"

static int	calc_size(char *path)
{
  int		count;
  int		pos;

  count = 1;
  pos = 0;
  while (path[pos] != '\0')
    {
      if (path[pos] == ':')
	count++;
      pos++;
    }
  return (count);
}

char		**save_paths(char **env)
{
  char		**back;
  char		*line;
  int		index;
  int		start;
  int		end;

  if ((line = my_search_env("PATH", env)) == NULL)
    return (NULL);
  if ((back = my_x_malloc(sizeof(char *) * (calc_size(line) + 1))) == NULL)
    return (NULL);
  index = 0;
  end = 0;
  while (end != my_strlen(line) && back)
    {
      start = end;
      end++;
      while (line[end] != ':' && line[end] != '\0')
	end++;
      if ((back[index] = my_x_malloc(sizeof(char) * (end - start + 1))) == NULL)
	return (NULL);
      back[index] = extract(line, start + 1, end);
      index++;
    }
  back[index] = NULL;
  return (back);
}

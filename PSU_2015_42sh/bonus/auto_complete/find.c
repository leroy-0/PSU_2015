/*
** find.c for find in /home/poinss_y/Documents/PSU/PSU_2015_42sh/bonus
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 13:29:04 2016 Yan Poinssot
** Last update Sun Jun  5 21:16:22 2016 leroy_0
*/

#include	<stdlib.h>
#include	<glob.h>
#include	<stdio.h>
#include	<string.h>
#include	"my.h"
#include	"bonus.h"

char		*extract_paths_dir(char *paths, char *command, int *cond)
{
  int		count;
  char		*inter;
  char		*back;

  count = 0;
  while (command[count] != '\0')
    {
      if (command[count] == '/')
	{
	  back = stitch(command, "*", "");
	  if (cond != NULL)
	    *cond = 0;
	  return (back);
	}
      count++;
    }
  inter = stitch(paths, command, "/");
  back = stitch(inter, "*", "");
  free(inter);
  return (back);
}

static char	*determine_display(glob_t *buffer, char *command)
{
  char		*back;

  (void)command;
  back = NULL;
  if (buffer->gl_pathc == 0)
    back = strdup("");
  return (back);
}

char		*extract_paths(char **paths, char *command, char *origin)
{
  glob_t	buffer;
  char		*analyse;
  char		*dir;
  char		*back;
  int		count;

  (void)origin;
  count = 1;
  analyse = extract_paths_dir(paths[1], command, &count);
  glob(analyse, 0, NULL, &buffer);
  free(analyse);
  while (paths[count] != NULL && count != 0)
    {
      analyse = extract_paths_dir(paths[count], command, NULL);
      glob(analyse, GLOB_APPEND, NULL, &buffer);
      count++;
      free(analyse);
    }
  dir = extract_dir(command, 1);
  if (buffer.gl_pathc > 0)
    display_possible(buffer.gl_pathv, dir, command);
  free(dir);
  back = determine_display(&buffer, command);
  globfree(&buffer);
  return (back);
}

char		*find_paths(char *origin, char *command, char **paths)
{
  (void)origin;
  if (paths == NULL)
    return (strdup(origin));
  return (extract_paths(paths, command, origin));
}

char		*find_current(char *origin, char *command)
{
  glob_t	buffer;
  char		*analyse;
  char		*dir;
  char		*back;

  (void)origin;
  analyse = extract_paths_dir(".", command, NULL);
  glob(analyse, 0, NULL, &buffer);
  free(analyse);
  dir = extract_dir(command, 1);
  free(dir);
  back = NULL;
  if (buffer.gl_pathc > 0)
    display_possible(buffer.gl_pathv, dir, command);
  back = determine_display(&buffer, command);
  globfree(&buffer);
  return (back);
}

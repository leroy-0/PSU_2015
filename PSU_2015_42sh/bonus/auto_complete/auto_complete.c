/*
** auto_complete.c for auto_complete in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 21:04:01 2016 leroy_0
** Last update Sun Jun  5 21:04:05 2016 leroy_0
*/

#include	<stdlib.h>
#include	<glob.h>
#include	<string.h>
#include	<stdio.h>
#include	"my.h"
#include	"bonus.h"

char		*auto_complete(char *command, t_cursor *cursor, char **env)
{
  char		**sep;
  char		*back;
  int		type;

  if (command == NULL)
    return (strdup(""));
  if ((sep = str_to_wordtab(command, ' ')) == NULL)
    back = find_paths(command, "", cursor->paths);
  else if ((type = find_type(command, sep)) == 0)
    back = find_paths(command, "", cursor->paths);
  else if (type == 1)
    back = find_paths(command, sep[my_tablen(sep) - 1], cursor->paths);
  else if (type == 2)
    back = find_current(command, "");
  else if (type == 3)
    back = find_current(command, sep[my_tablen(sep) -1]);
  if (back == NULL)
    {
      display_prompt(env);
      my_putstr(command);
    }
  cursor->x = strlen(command);
  return (strdup(command));
}

/*
** add_in_history.c for add_in_history in /home/longle_h/rendu/PSU_2015_42sh/bonus/history
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Sat Jun  4 15:58:22 2016 longle_h
** Last update Sun Jun  5 18:23:28 2016 bruere_s
*/

#include	<unistd.h>
#include	<string.h>
#include	"history.h"

int		is_valid_char(char c)
{
  if (c != '\0' && c != ' ' && c != '\t')
    return (0);
  return (1);
}

int		add_in_history(char *str, char *file)
{
  int		fd;

  fd = open_file_sh(2, file);
  if (fd == -1)
    return (1);
  if (strcmp(file, ".42_history") == 0)
    {
      if ((strncmp(str, "exit", 4) == 0 && is_valid_char(str[4]) == 1))
	return (1);
    }
  if (str != NULL)
    {
      write(fd, str, strlen(str));
      write(fd, "\n", 1);
    }
  close(fd);
  return (0);
}

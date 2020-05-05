/*
** auto_complete_func.c for auto_complete_func in /home/poinss_y/Documents/PSU/PSU_2015_42sh/bonus
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 13:14:04 2016 Yan Poinssot
** Last update Sun Jun  5 18:24:57 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	<glob.h>
#include	<string.h>
#include	"my.h"

int		my_strfcmp(char *word, char *words, int start)
{
  int		count;

  count = 0;
  if (word == NULL || words == NULL)
    return (1);
  while (words[count] != '\0')
    {
      if (words[count] != word[count + start])
	return (1);
      count++;
    }
  return (0);
}

static int	check_for_arg(int pos, char *command, char *check, int *counter)
{
  if (command[pos] == ' ' || command[pos] == '\t')
    (*counter)++;
  if (my_strfcmp(command, check, pos) == 0)
    {
      *counter = 1;
      if (pos + my_strlen(check) == my_strlen(command))
	*counter = 2;
      free(command);
      return (*counter);
    }
  return (-1);
}

static int	check_sep(char *line)
{
  static char	*check[] = {";", "<<", ">>", "<", ">", "|", "&&", "||"};
  char		*command;
  int		count;
  int		pos;
  int		counter;

  if ((command = flatten(line)) == NULL)
    return (0);
  count = 0;
  while (count < 8)
    {
      pos = my_strlen(command);
      counter = 0;
      while (pos >= 0 && counter < 2)
	{
	  if (check_for_arg(pos, command, check[count], &counter) != -1)
	    return (counter);
	  pos--;
	}
      count++;
    }
  free(command);
  return (0);
}

int		find_redir(char *command)
{
  int		count;

  count = 0;
  while (command[count] != '\0')
    {
      if (command[count] == '/')
	return (1);
      count++;
    }
  if (strcmp(command, ".") == 0 || strcmp(command, "..") == 0)
    return (1);
  return (0);
}

char		find_type(char *command, char **sep)
{
  if (find_redir(command) == 1)
    return (3);
  if (command[0] == '\0' ||
      ((command[my_strlen(command) - 1] == ' ' ||
	command[my_strlen(command) - 1] == '\t') &&
       my_tablen(sep) > 1 && check_sep(command) >= 1) ||
      (my_tablen(sep) > 1 && check_sep(command) == 2))
    return (0);
  if ((my_tablen(sep) > 1 && check_sep(command) >= 1) ||
      (((command[my_strlen(command) - 1] != ' ' &&
	 command[my_strlen(command) - 1] != '\t') && my_tablen(sep) == 1)))
    return (1);
  else if (command[my_strlen(command) - 1] == ' ' ||
	   command[my_strlen(command) - 1] == '\t')
    {
      return (2);
    }
  return (3);
}

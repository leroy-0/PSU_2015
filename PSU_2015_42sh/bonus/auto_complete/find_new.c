/*
** find_new.c for find new in /home/poinss_y/Documents/PSU/PSU_2015_42sh/bonus/auto_complete
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 19:13:10 2016 Yan Poinssot
** Last update Sun Jun  5 18:24:03 2016 Yan Poinssot
*/

#include	<stdlib.h>
#include	"my.h"
#include	"bonus.h"

char		*extract_last(char *word)
{
  int		count;

  if (word == NULL)
    return (NULL);
  count = my_strlen(word);
  while (count >= 0 && word[count] != '/')
    count--;
  if (word[count] == '/')
    count++;
  return (extract(word, count, my_strlen(word)));
}

static char	*extract_last_arg(char *word)
{
  int		count;

  count = my_strlen(word);
  while (count >= 0 && word[count] != '/' && word[count] != ' ' &&
	 word[count] != '\t')
    count--;
  if (count < 0 ||word[count] == '/' ||
      word[count] == '\t' || word[count] == ' ')
    count++;
  return (extract(word, count, my_strlen(word)));
}

static char	*check_new(char **table, int *status, char *first, int pos)
{
  int		index;
  char		*temps;
  char		*back;

  index = 1;
  while (table[index] != NULL && *status == 0)
    {
      temps = extract_last(table[index]);
      if (temps[pos] != first[pos])
	{
	  back = extract(temps, 0, pos);
	  return (back);
	}
      index++;
    }
  return (NULL);
}

static char	*find_new(char **table)
{
  int		pos;
  int		status;
  char		*back;
  char		*temp;

  if (my_tablen(table) == 1)
    return (extract_last(table[0]));
  pos = 0;
  back = NULL;
  status = 0;
  temp = extract_last(table[0]);
  while (status == 0 && temp[pos] != '\0')
    {
      back = check_new(table, &status, temp, pos);
      pos++;
    }
  if (back == NULL)
    return (extract(temp, 0, pos));
  return (back);
}

char		*print_new(char **table, char *command)
{
  char		*common;
  char		*new;
  char		*check;
  int		pos;

  if ((common = find_new(table)) == NULL)
    return (0);
  new = NULL;
  check = extract_last_arg(command);
  pos = my_strlen(common);
  while (pos >= 0)
    {
      if (my_strfcmp(common, check, pos) == 0)
	{
	  new = extract(common, pos + my_strlen(check), my_strlen(common));
	  pos = -1;
	}
      pos--;
    }
  if (pos != -2 && check != NULL)
    return (common);
  else if (new != NULL)
    return (new);
  return (NULL);
}

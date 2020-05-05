/*
** display.c for display in /home/poinss_y/Documents/PSU/PSU_2015_42sh/bonus/auto_complete
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Sat Jun  4 19:00:19 2016 Yan Poinssot
** Last update Sun Jun  5 18:25:21 2016 Yan Poinssot
*/

#include        <stdlib.h>
#include        <glob.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<string.h>
#include	"my.h"
#include	"bonus.h"

char		*extract_dir(char *command, int type)
{
  int		check;
  int		cursor;

  check = 0;
  cursor = 0;
  while (command[cursor] != '\0' && type == 0)
    {
      if (command[cursor] == '/')
	check = cursor;
      cursor++;
    }
  if (check == 0)
    return (strdup("."));
  return (extract(command, 0, check));
}

int		check_dir(char *command, char *address)
{
  char		*new_address;
  int		back;
  DIR		*dir;

  back = my_strlen(command);
  new_address = NULL;
  while (back > 0 && new_address == NULL)
    {
      if (command[back] == '/')
	new_address = strdup(command);
      back--;
    }
  if (new_address == NULL)
    new_address = stitch(address, command, "/");
  back = 1;
  if ((dir = opendir(new_address)) != NULL)
    {
      back = 0;
      my_putchar('/');
    }
  free(new_address);
  return (back);
}

int		display_word(char *word, char *dir)
{
  int		count;
  char		*display;
  int		size;

  count = my_strlen(word);
  while (word[count - 1] != '/' && count > 0)
    count--;
  display = extract(word, count, my_strlen(word));
  my_putstr(display);
  size = my_strlen(display) - count;
  size += check_dir(word, dir);
  free(display);
  return (size);
}

int		display_possible(char **table, char *dir, char *command)
{
  int		count;
  int		size;

  (void)command;
  count = 0;
  size = 0;
  my_putstr("\n");
  while (table[count] != NULL)
    {
      size += display_word(table[count], dir) + 1;
      my_putchar('\r');
      my_putchar('\n');
      count++;
    }
  return (size + 1);
}

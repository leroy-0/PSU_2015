/*
** echo.c for echo in /home/leroy_0/tek1/PSU_2015_42sh/built-in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed May  4 10:26:10 2016 leroy_0
** Last update Sat Jun  4 18:28:56 2016 leroy_0
*/

#include	<string.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"my.h"
#include	"built_in.h"

static int	print_special_char(t_echo *tab, char c)
{
  int		i;

  i = 0;
  if (c == 'c')
    return (1);
  while (i < 8)
    {
      if (tab[i].car == c)
	(tab[i].func)();
      i++;
    }
  return (0);
}

static int	loop_echo(char *cmd, int type, t_echo *tab)
{
  int		j;

  j = 0;
  while (cmd[j] != '\0')
    {
      if (cmd[j] != '\\')
	my_putchar(cmd[j]);
      else if (type == 1)
	{
	  if (print_special_char(tab, cmd[j + 1]) == 1)
	    return (1);
	  j++;
	}
      j++;
    }
  return (0);
}

static int	print_echo(char **cmd, int type, t_echo *tab)
{
  int		i;
  int		check;

  i = 0;
  check = 0;
  while (cmd[i] != NULL)
    {
      if (strcmp(cmd[i], "-e") != 0 && strcmp(cmd[i], "-n"))
	{
	  check = 1;
	  if ((loop_echo(cmd[i], type, tab)) == 1)
	    return (1);
	}
      if (check == 1 && cmd[i + 1] != NULL)
	my_putchar(' ');
      check = 0;
      i++;
    }
  if (type != 2)
    my_putchar('\n');
  return (0);
}

char		**my_echo(char *str, char **env)
{
  char		**cmd;
  t_echo	*tab;
  int		type;
  int		i;

  (void) (env);
  i = 0;
  type = 0;
  tab = init_tab();
  if ((cmd = str_to_wordtab(str, ' ')) == NULL)
    return (NULL);
  if (cmd == NULL || cmd[0] == NULL)
    return (0);
  while (cmd[i] != NULL)
    {
      if (strcmp(cmd[i], "-e") == 0)
	type = 1;
      if (strcmp(cmd[i], "-n") == 0)
	type = 2;
      i++;
    }
  free(tab);
  if ((print_echo(cmd, type, tab)) == 1)
    return (NULL);
  return (env);
}

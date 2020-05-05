/*
** check_tetrimino.c for check_tetrimino in /home/tekm/tek1/PSU_2015_bstetris
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Thu Feb 25 13:54:36 2016 Tekm
** Last update Thu Feb 25 15:18:23 2016 Tekm
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt])
    my_putchar(str[cpt++]);
}

int			check_tetrimino(int fd, char const *name)
{
  char		*str;
  char		s0;
  char		s1;
  char		s2;
  int		savecol;
  int		col;
  int		line;
  int		arg;
  int		cpt;

  line = 0;
  cpt = 0;
  arg = 0;
  col = 0;
  savecol = 0;
  my_putstr("Tetriminos : Name ");
  while (name[cpt] && name[cpt] != '/')
    cpt++;
  if (name[cpt] == '\0')
    cpt = 0;
  else
    cpt++;
  while (name[cpt] && name[cpt] != '.')
    my_putchar(name[cpt++]);
  my_putstr(" : ");
  cpt = 0;
  if ((str = get_next_line(fd)) != NULL)
    {
      while (str[cpt])
	{
	  if (str[cpt] != ' ')
	    {
	      if (arg == 0)
		{
		  s0 = str[cpt];
		  if (s0 < '1' || s0 > '9')
		    {
		      my_putstr("Error\n");
		      return (1);
		    }
		  arg = 1;
		}
	      else if (arg == 1)
		{
		  s1 = str[cpt];
		  if (s1 < '1' || s1 > '9')
		    {
		      my_putstr("Error\n");
		      return (1);
		    }
		  arg = 2;
		}
	      else if (arg == 2)
		{
		  s2 = str[cpt];
		  if (s2 < '1' || s2 > '9')
		    {
		      my_putstr("Error\n");
		      return (1);
		    }
		  break;
		}
	    }
	  cpt++;
	}
    }
  cpt = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      while (str[cpt])
	{
	  col++;
	  cpt++;
	}
      if (savecol <= col)
	savecol = col;
      line++;
      col = 0;
      cpt = 0;
    }
  if (savecol != (s0 - '0'))
    {
      my_putstr("Error\n");
      return (1);
    }
  if ((s1 - '0') != line)
    {
      my_putstr("Error\n");
      return (1);
    }
  if (s2 < '1' || s2 > '9')
    {
      my_putstr("Error\n");
      return (1);
    }
  else
    {
      fd = open(name, O_RDONLY);
      my_putstr("Size ");
      my_putchar(s0);
      my_putchar('*');
      my_putchar(s1);
      my_putstr(" : Color ");
      my_putchar(s2);
      my_putstr(" :\n");
      if ((str = get_next_line(fd)) != NULL)
	{}
      while ((str = get_next_line(fd)) != NULL)
	{
	  my_putstr(str);
	  my_putchar('\n');
	}
    }
  return (0);
}

int			main(int ac, char **av)
{
  int		fd;

  if (ac == 2)
    {
      fd = open(av[1], O_RDONLY);
      check_tetrimino(fd, av[1]);
    }
  else
    {
      my_putstr("Usage: ./check_tetrimino template\n");
      return (1);
    }
  return (0);
}

/*
** check_tetrimino.c for check_tetrimino in /home/tekm/tek1/PSU_2015_bstetris
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Thu Feb 25 13:54:36 2016 Tekm
** Last update Sun Mar 20 19:25:47 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

void			init_check(t_check *check, char const *name, int disp)
{
  check->line = 0;
  check->cpt = 0;
  check->arg = 0;
  check->col = 0;
  check->savecol = 0;
  check->s0 = '0';
  check->s1 = '0';
  check->s2 = '0';
  if (disp == 0)
    {
      my_putstr("Tetriminos : Name ");
      get_file_name(name);
    }
  if (disp == 0)
    my_putstr(" : ");
  check->cpt = 0;
}

void			disp_check_args(t_check *check, int fd,
					char const *path, int disp)
{
  int		cpt;
  int		cpt2;

  if (disp == 0)
    {
      fd = open(path, O_RDONLY);
      my_putstr("Size ");
      my_putchar(check->s0);
      my_putchar('*');
      my_putchar(check->s1);
      my_putstr(" : Color ");
      my_putchar(check->s2);
      my_putstr(" :\n");
      check->str = get_next_line(fd);
      while ((check->str = get_next_line(fd)) != NULL)
	{
	  cpt2 = 0;
	  cpt = my_strlen(check->str);
	  while (cpt != 0 && check->str[cpt] != '*')
	    cpt--;
	  while (cpt2 <= cpt)
	    my_putchar(check->str[cpt2++]);
	  my_putchar('\n');
	}
    }
}

int			final_checks(t_check *check,
				     int fd, char const *path, int disp)
{
  if ((check->s0 - '0') != check->col)
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  if ((check->s1 - '0') != check->line)
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  if (check->s2 < '1' || check->s2 > '9')
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  else
    disp_check_args(check, fd, path, disp);
  return (0);
}

int			go_check(t_check *check, int disp)
{
  while (check->str[check->cpt])
    {
      if (check->str[check->cpt] == '*')
	{
	  if (check->col <= check->cpt)
	    check->col = check->cpt;
	}
      else if (check->str[check->cpt] != '*'
	       && check->str[check->cpt] != ' ')
	{
	  if (disp == 0)
	    my_putstr("Error\n");
	  return (1);
	}
      check->cpt++;
    }
  return (0);
}

int			check_tetrimino(int fd, char const *name,
					char const *path, int disp)
{
  t_check		*check;

  check = malloc(sizeof(*check));
  init_check(check, name, disp);
  fd = open(path, O_RDONLY);
  if ((check->str = get_next_line(fd)) != NULL)
    {
      if (check_whl_args(check, disp) == 1)
	return (1);
    }
  check->cpt = 0;
  while ((check->str = get_next_line(fd)) != NULL)
    {
      if (go_check(check, disp) == 1)
	return (1);
      check->line++;
      check->cpt = 0;
    }
  check->col += 1;
  return (final_checks(check, fd, path, disp));
}

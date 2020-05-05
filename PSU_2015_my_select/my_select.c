/*
** my_select.c for my_select in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov 30 13:20:58 2015 leroy_0
** Last update Thu Dec 10 10:28:54 2015 leroy_0
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "include/my.h"

int	my_switch(t_struct *data)
{
  while ((data->ch = getch()) != 10 && data->ch != 10)
    {
      data->item = data->list[data->i];
      mvprintw(data->line, data->col, "%s", data->item);
      if (data->total == 0)
	return (0);
      if (data->ch == KEY_UP || data->ch == KEY_DOWN)
	my_key_updown(data);
      else if (data->ch == KEY_LEFT || data->ch == KEY_RIGHT)
      	my_key_leftright(data);
      else if (data->ch == ' ' || data->ch == KEY_BACKSPACE
	       || data->ch == KEY_DC)
      	my_key_space_enter(data);
      data->line = data->i;
      while (data->line > data->rowx)
	data->line -= data->rowx;
      attron(A_UNDERLINE);
      data->item = data->list[data->i];
      mvprintw(data->line, data->col, "%s", data->item);
      attroff(A_UNDERLINE);
      refresh();
      wrefresh(stdscr);
    }
  return (0);
}

void	my_return_list(t_struct	*data)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  data->new_list = malloc(sizeof(*data->new_list) * 20);
  while (a < data->total)
    data->new_list[a++] = malloc(sizeof(**data->new_list) * 50);
  a = 0;
  while (data->list[a] != NULL)
    {
      if (data->choose[a] == 1)
	{
	  data->new_list[b] = data->list[a];
	  b++;
	  data->new_list[b] = " ";
	  b++;
	}
      a++;
    }
  data->new_list[b - 1] = NULL;
  a = 0;
  while (data->new_list[a] != NULL)
    my_putstr(data->new_list[a++]);
}

void	my_list_alloc(t_struct *data)
{
  int	a;

  a = 1;
  data->list = malloc(sizeof(char *) * 20);
  while (a < data->total)
    {
      data->list[a] = malloc(sizeof(char) * my_strlen(data->str[a]));
      a++;
    }
  a = 1;
  while (data->str[a] != NULL)
    {
      data->list[a - 1] = data->str[a];
      a++;
    }
  data->list[a] = NULL;
  data->choose = malloc(sizeof(int) * data->total);
}

void    my_select(int total, char **str, t_struct *data)
{
  SCREEN	*my_scr;
  char	item[total];

  my_scr = newterm(NULL, stdin, stdin);
  data->item = item;
  data->total = total;
  data->str = str;
  my_list_alloc(data);
  my_display_result(data);
  wrefresh(stdscr);
  noecho();
  keypad(stdscr , TRUE);
  curs_set(0);
  data->i = 0;
  data->line = 0;
  data->col = 0;
  my_switch(data);
  endwin();
  delwin(stdscr);
  delscreen(my_scr);
}

int	main(int argc, char **argv, char **env)
{
  t_struct	*data;

  if (env == NULL || env[0] == NULL)
    {
      my_putstr("Error: Cannot open");
      return (1);
    }
  if (argc < 2)
    return (1);
  data = malloc(sizeof(*data));
  my_select((argc - 1), argv, data);
  my_return_list(data);
  return (0);
}

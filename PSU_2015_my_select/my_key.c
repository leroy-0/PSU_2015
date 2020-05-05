/*
** my_key.c for my_key in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Dec 10 10:25:30 2015 leroy_0
** Last update Thu Dec 10 10:27:16 2015 leroy_0
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "include/my.h"

void    my_key_updown(t_struct *data)
{
  if (data->ch == KEY_UP)
    {
      data->i--;
      data->i = (data->i < 0) ? (data->total - 1) : data->i;
      data->col = (data->i < (((data->col/20 + 1)*data->rowx) - data->rowx))
        ? data->col - 20 : data->col;
      data->col = (data->i == (data->total - 1)) ? data->maxcol : data->col;
    }
  else if (data->ch == KEY_DOWN)
    {
      data->i++;
      data->i = (data->i > (data->total - 1)) ? 0 : data->i;
      data->col = (data->i > ((data->col/20 + 1)*data->rowx))
        ? data->col + 20 : data->col;
      data->col = (data->i == 0) ? 0 : data->col;
    }
}

void    my_key_left(t_struct *data)
{
  data->i -= data->rowx;
  if (data->i < 0)
    {
      while (data->i < data->rowx*(data->maxcol/20))
        data->i += data->rowx;
      if (data->i > data->total - 1)
        data->i -= data->rowx;
    }
  data->col -= 20;
  if (data->col < 0)
    data->col = (data->i > (data->maxcol / 20) * data->rowx)
      ? data->maxcol : (data->maxcol - 20);
}

void    my_key_leftright(t_struct *data)
{
  if (data->ch == KEY_LEFT)
    my_key_left(data);
  else if (data->ch == KEY_RIGHT)
    {
      data->i += data->rowx;
      if (data->i > data->total - 1)
        {
          while (data->i >= data->rowx)
            data->i -= data->rowx;
        }
      data->col += 20;
      data->col = (data->i < data->rowx) ? 0 : data->col;
    }
}

void    my_key_enter(t_struct *data)
{
  data->choose[data->i] = (data->choose[data->i] == 1) ? 0 : 1;
  (data->choose[data->i] == 1) ? attron(A_REVERSE) : attroff(A_REVERSE);
  data->item = data->list[data->i];
  mvprintw(data->line, data->col, "%s", data->item);
  data->i++;
  data->i = (data->i > (data->total - 1)) ? 0 : data->i;
  data->item = data->list[data->i];
  data->line = data->i;
  mvprintw(data->line, data->col, "%s", data->item);
  if (data->choose[data->i] == 0)
    attroff(A_REVERSE);
}

void    my_key_space_enter(t_struct *data)
{
  if (data->ch == ' ')
    my_key_enter(data);
  else if (data->ch == KEY_BACKSPACE || data->ch == KEY_DC)
    {
      my_del_list(data);
      my_del_choose(data);
      data->total -= 1;
      data->i = (data->i > (data->total - 1)) ? 0 : data->i;
      data->i = (data->i < 0) ? (data->total - 1) : data->i;
      data->line = data->i;
      stdscr = newwin(0, 0, 0, 0);
      refresh();
      clear();
      keypad(stdscr , TRUE);
      my_display_result(data);
    }
}

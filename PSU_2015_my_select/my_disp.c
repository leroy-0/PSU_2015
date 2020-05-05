/*
** my_disp.c for my_disp in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Dec 10 10:24:29 2015 leroy_0
** Last update Thu Dec 10 10:24:58 2015 leroy_0
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "include/my.h"

void    my_prev_display(t_struct *data)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  while (a < data->total)
    {
      while (b < data->rowx && a < data->total)
	{
	  data->item = data->list[a];
	  mvprintw(b, data->maxcol, "%s", data->item);
	  a++;
	  b++;
	}
      data->maxcol += 20;
      b = 0;
    }
  data->maxcol -= 20;
}

void    my_display_result(t_struct *data)
{
  int   a;

  a = 0;
  data->maxcol = 0;
  getmaxyx(stdscr, data->rowx, data->coly);
  if (data->total < data->rowx)
    {
      while (a < data->total)
	{
	  data->item = data->list[a];
	  mvprintw(a, 0, "%s", data->item);
	  a++;
	}
    }
  else
    my_prev_display(data);
}

/*
** my_popup.c for my_popup in /home/leroy_0/rendu/PSU_2015_my_popup
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov 30 15:08:30 2015 leroy_0
** Last update Mon Nov 30 17:05:07 2015 leroy_0
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include "include/my.h"

void	my_middle_print(char *str)
{
  int	row;
  int	col;

  initscr();
  noecho();
  getmaxyx(stdscr,row,col);
  mvprintw(row/2,(col-strlen(str))/2,"%s",str);
  refresh();
  if (getch() == ' ')
    endwin();
  else
    {
      refresh();
      clear();
      my_middle_print(str);
    }
}

int	main(int argc, char **argv)
{
  if (argc != 2)
    return (1);
  my_middle_print(argv[1]);
  return (0);
}

/*
** my_del.c for my_del.c in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Dec 10 10:23:05 2015 leroy_0
** Last update Thu Dec 10 10:24:14 2015 leroy_0
*/

#include <sys/ioctl.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "include/my.h"

void    my_del_prev_choose(t_struct *data, int a)
{
  a = 0;
  while (a != data->i)
    {
      data->new_choose[a] = data->choose[a];
      a++;
    }
  a += 1;
  while (data->choose[a] != '\0')
    {
      data->new_choose[a - 1] = data->choose[a];
      a++;
    }
  data->new_choose[a - 1] = '\0';
  data->choose = data->new_choose;
}

void    my_del_choose(t_struct *data)
{
  int   a;

  a = 0;
  data->new_choose = malloc(sizeof(int) * data->total);
  if (data->i == data->total)
    {
      a = 0;
      while (a <= data->i)
        {
          data->new_choose[a] = data->choose[a];
          a++;
        }
      data->new_choose[a] = '\0';
      data->choose = data->new_choose;
    }
  else
    my_del_prev_choose(data, a);
}

void    my_del_prev_list(t_struct *data, int a)
{
  a = 0;
  while (a != data->i)
    {
      data->new_list[a] = data->list[a];
      a++;
    }
  a += 1;
  while (data->list[a] != NULL)
    {
      data->new_list[a - 1] = data->list[a];
      a++;
    }
  data->new_list[a - 1] = NULL;
  data->list = data->new_list;
}

void    my_del_list(t_struct *data)
{
  int   a;

  a = 0;
  data->new_list = malloc(sizeof(*data->new_list) * 20);
  while (a < data->total)
    {
      data->new_list[a] = malloc(sizeof(**data->new_list) * 50);
      a++;
    }
  if (data->i == data->total)
    {
      a = 0;
      while (a <= data->i)
        {
          data->new_list[a] = data->list[a];
          a++;
        }
      data->new_list[a] = NULL;
      data->list = data->new_list;
    }
  else
    my_del_prev_list(data, a);
}

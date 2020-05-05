/*
** getxy.c for getxy in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 13:25:33 2016 Arthur Klein
** Last update Thu Mar 17 19:50:29 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

int		get_y(char *str, int cpt, int nb)
{
  char		res[50];
  int		cpt_r;

  cpt_r = 0;
  while (str[cpt] && str[cpt] != ',')
    {
      res[cpt_r] = str[cpt];
      cpt_r++;
      cpt++;
    }
  res[cpt_r] = '\0';
  nb = my_strint(res);
  return (nb);
}

int		get_x(char *str, int cpt, int nb)
{
  char		res[50];
  int		cpt_r;

  cpt_r = 0;
  while (str[cpt] && str[cpt] != ',')
    cpt++;
  cpt++;
  while (str[cpt])
    {
      res[cpt_r] = str[cpt];
      cpt_r++;
      cpt++;
    }
  res[cpt_r] = '\0';
  nb = my_strint(res);
  return (nb);
}

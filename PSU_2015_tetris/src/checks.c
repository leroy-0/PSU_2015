/*
** checks.c for checks.c in /home/tekm/tek1/PSU_2015_tetris
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Thu Mar 17 20:59:24 2016 Tekm
** Last update Sun Mar 20 19:15:53 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

int			check_args0(t_check *check, int disp)
{
  check->s0 = check->str[check->cpt];
  if (check->s0 < '1' || check->s0 > '9')
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  check->arg = 1;
  return (0);
}

int			check_args1(t_check *check, int disp)
{
  check->s1 = check->str[check->cpt];
  if (check->s1 < '1' || check->s1 > '9')
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  check->arg = 2;
  return (0);
}

int			check_args2(t_check *check, int disp)
{
  check->s2 = check->str[check->cpt];
  if (check->s2 < '1' || check->s2 > '9')
    {
      if (disp == 0)
	my_putstr("Error\n");
      return (1);
    }
  return (0);
}

int                     check_file_name(char *str)
{
  char          *tetri;
  int           savecpt;
  int           cpt_c;
  int           cpt;

  cpt = 0;
  tetri = ".tetrimino";
  cpt = my_strlen(str);
  cpt_c = my_strlen(tetri);
  savecpt = cpt_c;
  while (cpt >= my_strlen(str) - savecpt)
    {
      if (str[cpt] != tetri[cpt_c])
        return (1);
      cpt_c--;
      cpt--;
    }
  return (0);
}

void                    run_tetrimins(char *str, DIR *dir_p,
                                      struct dirent *file_read, int fd)
{
  char                  **tetrimino_order;
  int                   cpt;
  int                   nb;

  cpt = 0;
  nb = 0;
  dir_p = opendir(str);
  while ((file_read = readdir(dir_p)) != NULL)
    if (check_file_name(file_read->d_name) == 0)
      nb++;
  tetrimino_order = malloc(sizeof(char *) * (nb + 1));
  dir_p = opendir(str);
  while ((file_read = readdir(dir_p)) != NULL)
    if (check_file_name(file_read->d_name) == 0)
      {
        tetrimino_order[cpt] =
          malloc(sizeof(char) * my_strlen(file_read->d_name) + 1);
        tetrimino_order[cpt]
          = my_strcpy(tetrimino_order[cpt], file_read->d_name);
        cpt++;
      }
  tetrimino_order[cpt] = NULL;
  tetrimino_order = order_it(tetrimino_order);
  load_tetriminos(fd, str, tetrimino_order);
}

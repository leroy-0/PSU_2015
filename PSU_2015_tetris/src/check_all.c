/*
** check_all.c for check_file in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 10:55:34 2016 Arthur Klein
** Last update Sun Mar 20 19:16:21 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

void			check_files(char *str, int fd)
{
  struct dirent		*file_read;
  DIR*			dir_p;
  int			nb;

  nb = 0;
  dir_p = opendir(str);
  while ((file_read = readdir(dir_p)) != NULL)
    if (check_file_name(file_read->d_name) == 0)
      nb++;
  my_putstr("Tetriminos : ");
  my_put_nbr(nb);
  my_putchar('\n');
  if (nb == 0)
    {
      my_putstr(
	"Error : we couldnt lauch tetris due to missing '.tetrimino' files\n");
      exit(1);
    }
  run_tetrimins(str, dir_p, file_read, fd);
}

int		checks_str(char *str, int cpt)
{
  if (str[cpt] == '\0')
    return (1);
  cpt++;
  if (str[cpt] == '\0')
    return (1);
  while (str[cpt])
    {
      if (str[cpt] < '0' || str[cpt] > '9')
	return (1);
      cpt++;
    }
  return (0);
}

int		check_str(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] && str[cpt] != '=')
    cpt++;
  if (str[cpt] == '=')
    {
      cpt++;
      if (str[cpt] == '\0')
	return (1);
      while (str[cpt] && str[cpt] != ',')
	{
	  if (str[cpt] < '0' || str[cpt] > '9')
	    return (1);
	  cpt++;
	}
      if (checks_str(str, cpt) == 1)
	return (1);
      return (0);
    }
  return (1);
}

int 		check_size(t_struct_d *data, int save_y, int save_x)
{
  if (save_y != data->size_y && save_x != data->size_x)
    {
      mvwin(stdscr, 0, 0);
      mvwin(data->score_w, data->size_y / 2.5, data->size_x / 7.5);
      mvwin(data->w, data->size_y * 0.09, data->size_x * 0.8);
      mvwin(data->name_w, data->size_y * (1 / 3), data->size_x / 8);
      mvwin(data->game_w, data->size_y * 0.1, data->size_x / 1.7);
    }
  if (data->size_y < 26 || data->size_x < 99)
    return (1);
  return (0);
}

int		check_level(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] && str[cpt] != '=')
    cpt++;
  if (str[cpt] == '=')
    {
      cpt++;
      if (str[cpt] == '\0')
	return (1);
      if (str[cpt] == '0' && str[cpt + 1] == '\0')
	return (1);
      while (str[cpt])
	{
	  if (str[cpt] < '0' || str[cpt] > '9')
	    return (1);
	  cpt++;
	}
      return (0);
    }
  return (1);
}

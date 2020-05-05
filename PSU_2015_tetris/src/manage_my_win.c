/*
** manage_my_win.c for manage_win in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 13:29:07 2016 Arthur Klein
** Last update Fri Mar 25 15:41:44 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

void		set_evry0(t_struct_d *data, int i, int j)
{
  i = 0;
  j = 0;
  while (data->tabs[i] != NULL)
    {
      while (data->tabs[i][j] != '\0')
	{
	  if (data->tabs[i][j] != '2')
	    data->tabs[i][j] = '0';
	  j++;
	}
      i++;
      j = 0;
    }
}

void 		change_value_to_2(t_struct_d *data, t_piece *tmp, int *start)
{
  int 		j;
  int 		i;
  int 		k;
  int 		l;

  k = 0;
  l = 0;
  i = (time(NULL) - *start) + data->down_k - 1;
  j = data->dep - 1;
  while (tmp->tetrimino[k] != NULL)
    {
      while (tmp->tetrimino[k][l] != '\0')
	{
	  if (tmp->tetrimino[k][l] == '*')
	    data->tabs[i][j] = '2';
	  j++;
	  l++;
	}
      l = 0;
      j = data->dep - 1;
      i++;
      k++;
    }
  set_evry0(data, i, j);
}

int		check_possible_pos(t_struct_d *data, t_piece *tmp, int start)
{
  int 		j;
  int 		i;
  int 		k;
  int 		l;

  k = 0;
  l = 0;
  i = (time(NULL) - start) + data->down_k;
  j = data->dep - 1;
  while (tmp->tetrimino[k] != NULL)
    {
      while (tmp->tetrimino[k][l] != '\0')
	{
	  if (tmp->tetrimino[k][l] == '*')
	    if (data->tabs[i][j] && data->tabs[i][j] == '2')
	      return (1);
	  j++;
	  l++;
	}
      l = 0;
      j = data->dep - 1;
      i++;
      k++;
    }
  return (0);
}

void 		show_list(t_piece **tmp, t_struct_d *data,
			  t_piece *string, int *start)
{
  int			i;

  i = 0;
  if (*tmp == NULL)
    *tmp = string;
  if (tmp != NULL)
    {
      if (data->sizes.y - (*tmp)->y >= i + (time(NULL) - *start) + data->down_k
	  && check_possible_pos(data, *tmp, *start) == 0)
	my_keys(data, *tmp, *start);
      else
	{
	  change_value_to_2(data, *tmp, start);
	  data->score += 10;
	  if (data->score == 200)
	    data->level += 1;
	  data->dep = data->sizes.x / 2 - (*tmp)->x / 2 + 1;
	  data->down_k = 0;
	  *start = time(NULL);
	  *tmp = (*tmp)->next;
	}
      i = 0;
    }
}

void		get_tetriminos(t_piece **string, char *path)
{
  char		**tetrimino;
  int 		fd;
  int 		i;
  int 		y;
  int 		x;

  i = 0;
  fd = open(path, O_RDONLY);
  get_next_line(fd);
  i = 0;
  while (get_next_line(fd) != NULL)
    i++;
  tetrimino = malloc(sizeof(char *) * (i + 1));
  fd = open(path, O_RDONLY);
  y = i;
  get_next_line(fd);
  i = 0;
  while ((path = get_next_line(fd)) != NULL)
    {
      x = my_strlen(path);
      tetrimino[i] = path;
      i++;
    }
  tetrimino[i] = NULL;
  my_putin(string, tetrimino, x, y);
}

int		my_loader(t_piece **string, struct dirent *read)
{
  static int		nb = 0;
  char			*path;
  int			fd;

  path = malloc(sizeof(char) * my_strlen("tetriminos/")
  + my_strlen(read->d_name) + 1);
  path = my_strcpy(path, "tetriminos/");
  path = my_strcat(path, read->d_name);
  fd = open(path, O_RDONLY);
  if (check_tetrimino(fd, read->d_name, path, 1) != 1)
    get_tetriminos(string, path);
  else
    nb++;
  return (nb);
}

int 	load_tetrimino(t_piece	**string)
{
  struct dirent		*read;
  DIR			*dir;
  int			nbtetri;
  int			nb;

  nb = 0;
  nbtetri = 0;
  if ((dir = opendir("tetriminos/")) == NULL)
    return (1);
  while ((read = readdir(dir)) != NULL)
    if (check_file_name(read->d_name) == 0)
      {
	if (my_loader(string, read) != 0)
	  nb++;
	nbtetri++;
      }
  if (nb == 1 && nbtetri == 1)
    {
      my_putstr("Error : only one tetrimino with error founded\n");
      return (1);
    }
  return (0);
}

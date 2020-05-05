/*
** manage_my_win.c for manage_win in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 13:29:07 2016 Arthur Klein
** Last update Thu Mar 24 17:35:06 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

int             opt_help(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  (void)(data);
  (void)(ctrl);
  print_my_error(av[0]);
  return (1);
}

void 		refresh_all(t_struct_d *data)
{
  wrefresh(data->w);
  wrefresh(data->score_w);
  wrefresh(data->game_w);
  wrefresh(data->name_w);
  wrefresh(stdscr);
}

int		my_putin(struct s_piece **list, char **tetrimino, int x, int y)
{
  t_piece	*elem;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->tetrimino = tetrimino;
  elem->x = x;
  elem->y = y;
  elem->next = *list;
  *list = elem;
  return (0);
}

void		opt_keys_game(t_struct_d *data, t_piece *tmp, int start, int i)
{
  int 		j;
  int 		save;

  j = 0;
  if (data->ch == KEY_RIGHT)
    {
      if (data->dep <= data->sizes.x - tmp->x)
	data->dep++;
      data->ch = 0;
    }
  else if (data->ch == KEY_LEFT)
    {
      if (data->dep > 1)
	data->dep--;
      data->ch = 0;
    }
  else if (data->ch == KEY_DOWN)
    {
      if (data->down_k + i
	  + (time(NULL) - start) + 1 < data->sizes.y - 1)
	data->down_k++;
      data->ch = 0;
    }
  else if (data->ch == KEY_UP)
    {
      data->ch = 0;
    }
  save = data->dep;
  while (tmp->tetrimino[i][j] != '\0')
    {
      mvwprintw(data->game_w, data->down_k + i
		+ (time(NULL) - start) + 1, data->dep, "%c", tmp->tetrimino[i][j]);
      if (data->tabs[data->down_k + i + (time(NULL) - start)] != NULL && tmp->tetrimino[i][j] == '*')
	data->tabs[data->down_k + i + (time(NULL) - start)][data->dep - 1] = '1';
      j++;
      data->dep++;
    }
  data->dep = save;
}

void 		check_move(t_struct_d *data, int y, t_piece *tmp)
{
  int 		i;
  int 		j;

  i = y - tmp->y - 2;
  j = 0;
  mvwprintw(stdscr, 30, 20, "%i", i);
  if (i >= 0)
    {
      while (data->tabs[i][j] != '\0')
	{
	  data->tabs[i][j] = '0';
	  j++;
	}
      i ++;
      j = 0;
      while (data->tabs[i][j] != '\0')
	{
	  data->tabs[i][j] = '0';
	  j++;
	}
    }
}

void		my_keys(t_struct_d *data, t_piece *tmp, int start)
{
  int			i;

  i = 0;
  while (tmp->tetrimino[i] != NULL)
    {
      if (data->ch == 'p' && data->pause_k == 0)
	data->pause_k = 1;
      else if (data->ch == 'p' && data->pause_k == 1)
	data->pause_k = 0;
      if (data->pause_k == 0)
	opt_keys_game(data, tmp, start, i);
      else
	mvwprintw(data->game_w, data->down_k + i
		  + (time(NULL) - start) + 1, data->dep, "%s\n", tmp->tetrimino[i]);
      i++;
    }
}

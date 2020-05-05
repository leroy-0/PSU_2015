/*
** manage_my_win.c for manage_win in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 13:29:07 2016 Arthur Klein
** Last update Fri Mar 25 15:52:42 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

void		show_stack(t_struct_d *data)
{
  int			i;
  int			j;

  i = 0;
  while (data->tabs[i] != NULL)
    {
      j = 0;
      while (data->tabs[i][j] != '\0')
	{
	  if (data->tabs[i][j] == '2')
	    mvwprintw(data->game_w, i + 1, j + 1, "%c", '*');
	  j++;
	}
      i++;
    }
}

void 		show_next(t_piece *tmp, t_struct_d *data, t_piece *string)
{
  int			i;
  int 			j;

  i = 1;
  j = 0;
  if (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  else
    tmp = string;
  werase(data->w);
  while (tmp->tetrimino[j] != NULL)
    {
      mvwprintw(data->w, i, 5, "%s\n", tmp->tetrimino[j++]);
      i++;
    }
}

void 		show_tabs(t_struct_d *data)
{
  int 		i;

  i = 0;
  while (data->tabs[i] != NULL)
    {
      mvwprintw(stdscr, i, 1, "%s\n", data->tabs[i]);
      i++;
    }
}

void		check_game(t_struct_d *data)
{
  int		cpt;

  cpt = 0;
  while (data->tabs[0][cpt])
    {
      if (data->tabs[0][cpt] == '2')
	{
	  end_win();
	  my_putstr("GAME OVER\n");
	  exit(1);
	}
      cpt++;
    }
}

int		my_switcher(t_struct_d *data, t_piece **tmp,
			    t_piece *string, int *start)
{
  int 		save_x;
  int 		save_y;

  save_x = data->size_x;
  save_y = data->size_y;
  getmaxyx(stdscr, data->size_y, data->size_x);
  if (check_size(data, save_y, save_x) == 1)
    return (1);
  werase(data->game_w);
  check_game(data);
  show_list(tmp, data, string, start);
  show_next(*tmp, data, string);
  show_stack(data);
  disp_name(data);
  disp_game(data);
  disp_score(data);
  disp_next(data);
  refresh_all(data);
  return (0);
}

int		my_switch(t_struct_d *data, SCREEN *my_scr)
{
  t_piece	*string;
  t_piece	*tmp;
  int 		start;

  (void)my_scr;
  string = NULL;
  data->startt = time(NULL);
  start = time(NULL);
  nodelay(stdscr, true);
  if (load_tetrimino(&string) == 1)
    return (1);
  data->tabs = NULL;
  data->tabs = malloc_init(data->tabs, data);
  data->dep = data->sizes.x / 2 - string->x / 2 + 1;
  tmp = string;
  while ((data->ch = getch()) != data->quit[0])
    if (my_switcher(data, &tmp, string, &start) == 1)
      return (1);
  return (0);
}

int 		end_win(t_struct_d *data, int i, SCREEN *my_scr)
{
  endwin();
  delwin(stdscr);
  delwin(data->w);
  delwin(data->name_w);
  delwin(data->score_w);
  delwin(data->game_w);
  delscreen(my_scr);
  return (i);
}

int		tetris(t_struct_d *data)
{
  SCREEN	*my_scr;

  if (data->sizes.x < 8 || data->sizes.y < 8)
    {
      my_putstr("Error : Map size too small\n");
      exit(1);
    }
  my_scr = newterm(NULL, stdin, stdin);
  if (my_scr == NULL)
    exit(1);
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  if (has_colors() == FALSE)
    {
      endwin();
      delwin(stdscr);
      my_putstr("Your terminal does not support color\n");
    }
  getmaxyx(stdscr, data->size_y, data->size_x);
  data->score_w = newwin(12, 19, data->size_y / 2.5, data->size_x / 7.5);
  data->w = newwin(8, 12, data->size_y * 0.09, data->size_x * 0.8);
  data->game_w = newwin(data->sizes.y + 2,
			data->sizes.x + 2, data->size_y * 0.1, data->size_x / 1.7);
  data->name_w = newwin(6, 44, data->size_y * (1 / 3), data->size_x / 8);
  if (my_switch(data, my_scr) == 1)
    return (end_win(data, 1, my_scr));
  return (end_win(data, 0, my_scr));
}

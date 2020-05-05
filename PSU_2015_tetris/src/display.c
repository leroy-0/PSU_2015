/*
** display.c for display in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 10:42:31 2016 Arthur Klein
** Last update Fri Mar 18 18:02:41 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

void		disp_score(t_struct_d *data)
{
  if (data->pause_k == 0)
    data->real_t = time(NULL) - data->startt;
  if (data->real_t == 60)
    {
      data->min += 1;
      data->startt += 60;
      data->real_t = 0;
    }
  wborder(data->score_w, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(data->score_w, 2, 2, "%s", "High Score");
  mvwprintw(data->score_w, 2, 15, "%d", data->highscore);
  mvwprintw(data->score_w, 3, 2, "%s", "Score");
  mvwprintw(data->score_w, 3, 15, "%d", data->score);
  mvwprintw(data->score_w, 5, 2, "%s", "Lines");
  mvwprintw(data->score_w, 5, 15, "%d", data->sizes.y);
  mvwprintw(data->score_w, 7, 2, "%s", "Level");
  mvwprintw(data->score_w, 7, 15, "%d", data->level);
  mvwprintw(data->score_w, 9, 2, "%s", "Time:");
  secnd_score(data, data->real_t);
}

void		disp_name(t_struct_d *data)
{
  mvwprintw(data->name_w, 0, 0, "%s",
	    " _____  _____  _____  _____  _____  ______  ");
  mvwprintw(data->name_w, 1, 0, "%s",
	    "   |   |         |   |     |   |   |        ");
  mvwprintw(data->name_w, 2, 0, "%s",
	    "   |   |_____    |   |____/    |   |______  ");
  mvwprintw(data->name_w, 3, 0, "%s",
	    "   |   |         |   |    \\    |          | ");
  mvwprintw(data->name_w, 4, 0, "%s",
	    "   |   |_____    |   |     \\ __|__  ______| ");
  mvwprintw(data->name_w, 5, 0, "%s",
	    "                                            ");
}

void		disp_game(t_struct_d *data)
{
  wborder(data->game_w, '|', '|', '-', '-', '-', '-', '-', '-');
}

void		disp_next(t_struct_d *data)
{
  wborder(data->w, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(data->w, 0, 1, "%s", "Next");
}

void		secnd_score(t_struct_d *data, time_t realt)
{
  if (realt < 10)
    {
      mvwprintw(data->score_w, 9, 11, "%d", 0);
      mvwprintw(data->score_w, 9, 12, "%d", 0);
      mvwprintw(data->score_w, 9, 13, "%s", ":");
      mvwprintw(data->score_w, 9, 14, "%d", 0);
      mvwprintw(data->score_w, 9, 15, "%d", realt);
    }
  else
    mvwprintw(data->score_w, 9, 14, "%d", realt);
  if (data->min < 9)
    {
      mvwprintw(data->score_w, 9, 11, "%d", 0);
      mvwprintw(data->score_w, 9, 12, "%d", data->min);
      mvwprintw(data->score_w, 9, 13, "%s", ":");
    }
  else
    mvwprintw(data->score_w, 9, 11, "%d", data->min);
  mvprintw((data->size_y - 2), (data->size_x / 4) - 10,
	   "%s", "EpiTetris(c) - 2016");
}

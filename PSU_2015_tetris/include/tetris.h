/*
** tetris.h for tetris.h in /home/tekm/tek1/PSU_2015_tetris
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Tue Feb 23 17:18:44 2016 Tekm
** Last update Fri Mar 18 17:57:50 2016 Tekm
*/

#include "my.h"

#ifndef TETRIS_H_
# define TETRIS_H_

typedef struct 		s_struct_control
  {
    int i;
    int t;
    int j;
    int aff;
    int where;
    int	ac;
  }			t_ctrl;

typedef struct		s_struct_size
  {
    int		x;
    int		y;
  }			t_struct_size;

typedef struct    s_piece
  {
    char      **tetrimino;
    int 		x;
    int 		y;
    int 		color;
    struct s_piece   *next;
  }     t_piece;

typedef struct		s_struct_check
  {
    char          *str;
    char          s0;
    char          s1;
    char          s2;
    int           savecol;
    int           col;
    int           line;
    int           arg;
    int           cpt;
  }			t_check;

typedef struct		s_struct_d
  {
    WINDOW        	*w;
    WINDOW        	*score_w;
    WINDOW		*game_w;
    WINDOW 		*name_w;
    int			ch;
    int			size_x;
    int			size_y;
    time_t		startt;
    time_t		min;
    int			highscore;
    int			score;
    int			line;
    int			level;
    char		*left;
    char		*right;
    char		*turn;
    char		*drop;
    char		*quit;
    char		*pause;
    char		*next;
    int			down_k;
    int			pause_k;
    int			real_t;
    int			dep;
      char      **tabs;
    int			tetrimino;
    t_struct_size	sizes;
  }		t_struct_d;

typedef struct 	s_struct_ptr_fnct
  {
    char	 *opt[2];
    int		(*ptr)(t_struct_d *, char **av, t_ctrl *);
  } 	t_ptr_fnct;

#endif /* !TETRIS_H_ */

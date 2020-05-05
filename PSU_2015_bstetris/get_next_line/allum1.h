/*
** allum1.c for allum1.h in /home/tekm/tek1/CPE_2015_Allum1
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Thu Feb 11 17:07:05 2016 Tekm
** Last update Sun Feb 21 19:42:11 2016 Tekm
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

#include "get_next_line.h"

void            print_board(t_struct_d *data);
void            replace_line(t_struct_d *data, char *saveline, int player);
int             update_board(t_struct_d *data, int player,
			     int cpt, char *saveline);
void            print_updated_board_game(t_struct_d *data, int player);
void            init_map(t_struct_d *data);
int             check_my_game(char **map);
int             my_errors_l(int player, int line, char **map);
int             my_prev_err(int player, int line, int nb_matches, char **map);
int             my_errors_m(int player, int line, int nb_matches, char **map);
int             ai_turn(t_struct_d *data);

# endif /* ALLUM1_H_ */

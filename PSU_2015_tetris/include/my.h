/*
** my.h for my.h in /home/leroy_0/rendu/Piscine_C_J09/ex_02
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  8 13:42:23 2015 maxime leroy
** Last update Fri Mar 25 15:52:53 2016 Tekm
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include "tetris.h"

t_ptr_fnct	*init_data();
char            *get_modified_space(char *str);
char            *get_mdf_space(char *tmp, char *str, int cpt_t, int nb);
int             check_space(char *str);
char            *get_modified_sequ(char *str);
char            *get_mdf_sequ(char *tmp, char *str, int cpt_t, int nb);
int             check_sequ(char *str);
int             check_file_name(char *str);
char            *get_file_name(const char *str);
char            *get_that_key(char *str);
void             run_tetrimins(char *str, DIR *dir_p,
struct dirent *file_read, int fd);
void            load_tetriminos(int fd, char *str, char **tetrimino_order);
char            **order_it(char **tetrimino_order);
int             check_whl_args(t_check *check, int disp);
void             my_keys(t_struct_d *data, t_piece *tmp, int start);
int             my_putin(struct s_piece **list,
char **tetrimino, int x, int y);
void            show_list(t_piece **tmp, t_struct_d *data,
t_piece *string, int *start);
int		load_tetrimino(t_piece  **string);
int		check_tetrimino(int, char const *, char const *, int);
void            refresh_all(t_struct_d *data);
void 		my_putstr(char *);
void		my_putchar(char);
void		my_put_nbr(int);
int    		my_strlen(char *);
char   		*my_strcpy(char *, char *);
char   	 	*my_strcat(char *, char *);
int     	my_strcmp(char *, char *);
int     	my_strint(char *);
int     	my_strncmp(char *, char *, int);
char    	*my_strnbr(long);
char    	*my_revstr(char *str);
int 		opt_without_next(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		debug_mode(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_mapsize(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_keypause(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_keydrop(t_struct_d *data, char **av, t_ctrl *ctrl);
int       	check_equal(char *);
char 		*get_equal(char *);
int		check_str(char *str);
int		get_sizes(char *str, int nb);
void		show_debug(t_struct_d *data);
void            show_stack(t_struct_d *data);
int             check_possible_pos(t_struct_d *data, t_piece *tmp, int start);
int		keypress();
int 		opt_keyleft(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_keyquit(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_keyright(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_keyturn(t_struct_d *data, char **av, t_ctrl *ctrl);
void		disp_score(t_struct_d *data);
void		disp_name(t_struct_d *data);
void		disp_game(t_struct_d *data);
void		disp_next(t_struct_d *data);
void		secnd_score(t_struct_d *data, time_t realt);
int 		opt_help(t_struct_d *data, char **av, t_ctrl *ctrl);
int 		opt_level(t_struct_d *data, char **av, t_ctrl *ctrl);
int		manage_my_arg(char **av, t_ptr_fnct *tabs,
			      int ac, t_struct_d *data);
void    	check_files(char *str, int fd);
int		checks_str(char *str, int cpt);
int		check_str(char *str);
int 		check_size(t_struct_d *data, int save_y, int save_x);
int		check_level(char *str);
void 		print_my_error(char *name);
void		show_debugs(t_struct_d *data);
void		show_debug(t_struct_d *data);
int		get_x(char *str, int cpt, int nb);
int		get_y(char *str, int cpt, int nb);
int		get_sizes(char *str, int nb);
int		check_int(char *str);
int		check_equal(char *str);
char		*get_equal(char *str);
int             check_args0(t_check *check, int);
int             check_args1(t_check *check, int);
int             check_args2(t_check *check, int);
int		tetris(t_struct_d *data);
int 		key_drop_long(char **av, t_ctrl *ctrl, t_struct_d *data);
int 		key_pause_long(char **av, t_ctrl *ctrl, t_struct_d *data);
int 		key_turn_long(char **av, t_ctrl *ctrl, t_struct_d *data);
int 		key_right_long(char **av, t_ctrl *ctrl, t_struct_d *data);
int 		key_quit_long(char **av, t_ctrl *ctrl, t_struct_d *data);
char            *get_mdf_space(char *tmp, char *str, int cpt_t, int nb);
char            *get_modified_space(char *str);
int             check_sequ(char *str);
char            *get_mdf_sequ(char *tmp, char *str, int cpt_t, int nb);
char            *get_modified_sequ(char *str);
int 		key_left_long(char **av, t_ctrl *ctrl, t_struct_d *data);
char    	**malloc_init(char **tabs, t_struct_d *data);
#endif /* !MY_H_ */

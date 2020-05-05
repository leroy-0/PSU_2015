/*
** bonus.h for bonus in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:51:42 2016 leroy_0
** Last update Sun Jun  5 21:13:08 2016 leroy_0
*/

#ifndef		BONUS_H_
# define	BONUS_H_

typedef struct  s_struct_cursor
{
  int           x;
  int		ch;
  int		pass;
  char		**paths;
}               t_cursor;

typedef struct	s_struct_ptrs
{
  char          *(*ptr)(char *str, t_cursor *cursor, char **env);
  int		nb;
}		t_ptrs;

char			*find_paths(char *origin,
				    char *command, char **paths);
char			*find_current(char *origin, char *command);
char			*print_new(char **table, char *commmand);
char			*auto_complete(char *command,
				       t_cursor *cursor, char **env);
char			find_type(char *command, char **sep);
int			display_possible(char **table, char *dir, char *com);
char			*extract_last(char *word);
int			my_strfcmp(char *word, char *words, int pos);
char			**save_paths(char **env);
char			*extract_dir(char *command, int type);
int			init_term(int reset, char **env);
char			*my_getstr(char **env);
char			*delete_char(char *str, int where);
void			action_key(char *str);
char			*save_str(char *str, int ch);
t_ptrs			*init_ptrs();
char			*my_return_to_line(char *str, t_cursor *cursor,
					   char **env);
char			*my_move_cursor(char *str, t_cursor *cursor,
					char **env);
int			which_action(char *str, char ch);
char			*my_backspace(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_a(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_c(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_e(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_l(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_u(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_w(char *str, t_cursor *cursor, char **env);
char			*my_ctrl_k(char *str, t_cursor *cursor, char **env);
void			my_cursor_left(t_cursor *cursor);
void			my_cursor_right(t_cursor *cursor, char *str);
char			*my_cursor_up(char *str, t_cursor *cursor,
				      char **env);
char			*my_cursor_down(char *str, t_cursor *cursor,
					char **env);
char			*get_current_str(t_cursor *cursor,
					 char *str, int ch, char *tmp);
t_ptrs			*init_values(t_cursor *cursor, char **paths);

#endif		/* !BONUS_H_ */

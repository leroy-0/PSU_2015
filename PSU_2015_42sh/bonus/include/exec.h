/*
** exec.h for exec in /home/longle_h/rendu/PSU_2015_42sh/exec
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Fri May  6 12:51:26 2016 longle_h
** Last update Sat Jun  4 23:02:20 2016 bruere_s
*/

#ifndef		EXEC_H_
# define	EXEC_H_

#include	"built_in.h"

char		*find_good_path(char **path, char *to_find);
int		my_simple_exec(char *str, char ***env, int pid, int *res);
void		my_put_not_found(char *name);
int		fill_ptr_fnc(t_built *in, char *str, char ***env);
void		puterr(char *str);
int		write_seg(int i, char *prog);
char		**change_local_variables(char **av, char **env);
char		*change_local_variables_str(char *str, char **env);
char		*change_variable_history(char *s);
char            *check_globing(char *s);

#endif		/* EXEC_H_ */

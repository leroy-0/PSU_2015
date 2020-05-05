/*
** history.h for history in /home/longle_h/rendu/PSU_2015_42sh/bonus/history
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Sat Jun  4 15:46:52 2016 longle_h
** Last update Sun Jun  5 18:25:56 2016 bruere_s
*/

#ifndef		HISTORY_H_
# define	HISTORY_H_

char		**gimme_hist(void);
int		open_file_sh(int mode, char *file);
int		add_in_history(char *str, char *file);
char		*move_hist(char todo, char **env);
char		**read_tab(int fd, char **hist);

#endif		/* HISTORY_H_ */

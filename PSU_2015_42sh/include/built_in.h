/*
** built_in.h for built_in in /home/leroy_0/tek1/PSU_2015_42sh/built-in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed May  4 08:44:39 2016 leroy_0
** Last update Sat Jun  4 13:34:49 2016 bruere_s
*/

#ifndef		BUILT_IN_H_
# define	BUILT_IN_H_

typedef struct	s_built
{
  char		*built;
  char		**(*ptr)(char *str, char **env);
}		t_built;

typedef struct	s_echo
{
  char		car;
  void		(*func)();
}		t_echo;

char		**my_get_env(char **env);
char		**my_putenv(char *look, char *s, char **env);
char		*my_search_env(char *str, char **env);
void		free_tab(char **tab);
char		*get_cmd(char *str);
char		**my_cd(char *str, char **env);
char		**my_cd_home(char ***env);
char		**my_cd_directory(char ***env, char *str);
char		**my_cd_oldpwd(char ***env);
char		**my_env(char *str, char **env);
char		**my_unsetenv(char *str, char **env);
char		**my_setenv(char *str, char **env);
char		**my_exit(char *str, char **env);
t_echo		*init_tab();
char		**my_echo(char *str, char **env);
char		**my_putenvend(char *look, char *s, char **myenv);

/*
** Pointeurs sur fonctions echo
*/

void		print_a_echo(void);
void		print_b_echo(void);
void		print_e_echo(void);
void		print_f_echo(void);
void		print_n_echo(void);
void		print_r_echo(void);
void		print_t_echo(void);
void		print_v_echo(void);

#endif          /* !BUILT_IN_H_ */

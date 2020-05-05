/*
** built_in.h for built_in in /home/leroy_0/tek1/PSU_2015_42sh/built-in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed May  4 08:44:39 2016 leroy_0
** Last update Sun Jun  5 22:54:33 2016 bruere_s
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

typedef struct	s_echo_special
{
  char		car;
  char		*(*func_special)(char *);
}		t_echo_special;

char		**my_get_env(char **env);
char		**my_putenv(char *look, char *s, char **env);
char		*my_search_env(char *str, char **env);
void		free_tab(char **mytab);
char		*get_cmd(char *str);
char		**my_cd(char *str, char **env);
char		**my_cd_home(char ***env);
char		**my_cd_directory(char ***env, char *str);
char		**my_cd_oldpwd(char ***env);
char		**my_env(char *str, char **env);
char		**my_unsetenv(char *str, char **env);
char		**my_setenv(char *str, char **env);
char		**my_exit(char *str, char **env);
char		**my_alias(char *str, char **env);
char		**aff_history(char *str, char **env);
t_echo		*init_tab();
char		**my_echo(char *str, char **env);
char		**my_putenvend(char *look, char *s, char **myenv);
int		check_good_alias(char *s, int mode);

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
char		*echo_O_special(char *);
char		*echo_n_special(char *);
char		*echo_sharp_special(char *);
char		*echo_star_special(char *);
char		*echo_at_special(char *);
char		*echo_inte_special(char *);
char		*echo_dollard_special(char *);
char		*echo_excla_special(char *);

#endif          /* !BUILT_IN_H_ */

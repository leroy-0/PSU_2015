/*
** mysh.h for mysh.h in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:01:42 2016 leroy_0
** Last update Thu Apr 21 10:21:50 2016 leroy_0
*/

#ifndef MYSH_H_
# define MYSH_H_

char            *epur_str(char *str);
int             s_cmp(char *dest, char *src);
void            my_get_env(t_struct_d *data, char **envp);
void            my_wait_ch();
void            my_forkit(t_struct_d *data, char **envp);
int             my_whil(t_struct_d *data, int a, int b, char *str);
char            *my_envir(char **envp, int a);
char            *my_getpath(char **envp, char *name);
void            my_get_envtab(t_struct_d *data, char *env);
int             my_which_find(t_struct_d *data, char **arg, int fd, int b);
int             my_finder_antes(t_struct_d *data, char **arg, int fd);
int             my_finder(t_struct_d *data, char **arg);
int             my_find(t_struct_d *data, char **arg);
void            my_get_args(t_struct_d *data, char *str);
char            **my_get_newenv(t_struct_d *data, int a, int b);
void            my_unsetenvir(t_struct_d *data, char *str);
void            my_setenvir_antes(t_struct_d *data,
                                  char *arg1, char *arg2, int a);
char            **my_other_set(t_struct_d *data, char *arg1, char *arg2);
void            my_final_set(t_struct_d *data, char *arg1, char *arg2, int a);
int             my_setenvir(t_struct_d *data,
                            char *str, char *arg1, char *arg2);
void            my_showenvir(t_struct_d *data);
char            *my_execute(t_struct_d *data, char *str);
int             my_options(t_struct_d *data, char *str);
char            *my_minish_execute(t_struct_d *data, char *str);
void            my_minish(t_struct_d *data);
int             my_pipe(t_struct_d *data, char *str);
void            my_redir_right(t_struct_d *data, char ***cmds);
void            my_redir_left(t_struct_d *data, char *str, char ***cmds);
void            my_redir_rightdouble(t_struct_d *data, char ***cmds);
void            my_redir_leftdouble(t_struct_d *data, char *str, char ***cmds);
char            *get_command(char *str, int where, int cpt);
int             check_line(char *str);
int             check_pipes(char *tmp);
void            my_ctrlc();
void            my_cdopt(t_struct_d *data, char *str);
char            ***get_all_args(t_struct_d *data, int argc,
                                char **argv, int round);
int             check_redir(char *str);
char            **get_cut_args(t_pipe *piper, char *str, int nbargs, char ch);
int             check_pipe(char *str);
void            run_pipe(t_struct_d *data, t_pipe *piper);
char            **my_get_args_p(char *str);
void            run_redir_rd(t_struct_d *data, char ***cmds, int out);
void            *my_x_malloc(int size);
int             check_strrandom(char *str);

#endif /* !MYSH_H_ */

/*
** my.h for my in /home/bruere_s/rendu/Piscine_C_J09/include
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:55:12 2015 sebastien bruere
** Last update Sun Jun  5 21:28:47 2016 bruere_s
*/

#ifndef		MY_H_
# define	MY_H_

# define	MAX_PATH_LEN		4096

#include	<stdlib.h>

int		my_putchar(char c);
int		my_putcerr(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
void		*my_x_malloc(size_t size);
int		my_swap(int *a, int *b);
char		*epur_str(char *s);
char		*epur_virgule(char *str);
char		*my_strdup(char *src);
int		my_strlen(char *str);
int		my_putstr(char *str);
char		**my_puterr(char *str);
int		send_err(char *before, char *message, int back);
int		my_getnbr(char *str);
int		nb_word(char *str, char sep);
int		lenght_to_sep(char *s, int i, char sep);
char		**str_to_wordtab(char *s, char sep);
void		my_sort_int_tab(int *my_tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
char		*my_itoa(int x);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
char		*my_str_cut(char *s, int j);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_tablen(char **my_tab);
int		check_ambigous(char **op);
char		*extract(char *tmp, int start, int end);
char		*stitch(char *tmp, char *tmps, char *sep);
char		*flatten(char *word);
char		*tab_to_str(char **my_tab);
void            display_prompt(char **env);
char		*epur_quote(char *s);
char		*display_error_local_variable(char *s);
char		**display_error_local_variable_tab(char *s);
int		is_direct_path(char *to_find);
char		**put_slash_in_path(char **old_path);

#endif		/* !MY_H_ */

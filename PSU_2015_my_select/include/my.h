/*
** my.h for my.h in /home/leroy_0/rendu/Piscine_C_J09/ex_02
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  8 13:42:23 2015 maxime leroy
** Last update Thu Dec 10 10:33:00 2015 leroy_0
*/

#ifndef MY_H_
# define MY_H_

#include <stdarg.h>
#include "../structure.h"

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strnbcpy(char *dest, char *src, int nb, int nb2);
char	*my_strnbr(long nb);
char    *no_space(char *str);
char    *my_strnberase(char *src, int nb, int nb2);
char    *my_strnbput(char *dest, char *src, int nb);
int     number(char **str);
int     summands(char **str);
long    fact_condi(char **str, long ret);
int     factors(char **str);
char    *replace_left(char *str);
char    *replace_right(char *str);
int     replace_middle(char *str);
char    *verify(char *str, char *tmpleft);
char    *calculate_prev(char *str);
char    *calculate(char *tmpleft);
char    *calc_par(char *str, int a, int b, int counter);
char    *par_verify(char *str, int a, int b, int counter);
int     error1(char *str);
char    *pre_exec(char *str, char *tmp, int c, int a);
char    *execute(char *str, int counter);
char    *final_execute(char *str);
char    *buffer();
int     error(char *str);
int     error2(char *str);
int     error3(char *str);
int     error4(char *str);
int     my_strint(char *str);
char    *binary(unsigned long nb, int base);
char    *hexa(unsigned long nb, int basenb, char *base);
char    *my_strunnbr(unsigned int nb);
char    *my_strnbput(char *dest, char *src, int nb);
char    *my_strprintS(char *str);
char    *my_condif(int counter, char *s, va_list tmp, char *res);
char    *my_condif2(int counter, char *s, char *res);
int     my_display(int counter, char *s, va_list tmp);
int     my_while_exec_prev(char *s, int counter);
int     my_while_exec(char *s, int counter, va_list tmp, int res);
int     my_exec(char *s, va_list tmp);
char    *my_while_printf(int a, int b, char *res, char *s);
int     my_printf(char *s, ...);
void    my_del_prev_choose(t_struct *data, int a);
void    my_del_choose(t_struct *data);
void    my_del_prev_list(t_struct *data, int a);
void    my_del_list(t_struct *data);
void    my_prev_display(t_struct *data);
void    my_display_result(t_struct *data);
void    my_key_updown(t_struct *data);
void    my_key_left(t_struct *data);
void    my_key_leftright(t_struct *data);
void    my_key_enter(t_struct *data);
void    my_key_space_enter(t_struct *data);

#endif /* !MY_H_ */

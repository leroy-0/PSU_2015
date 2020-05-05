/*
** my.h for my.h in /home/leroy_0/rendu/Piscine_C_J09/ex_02
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  8 13:42:23 2015 maxime leroy
** Last update Sun Feb 21 18:53:16 2016 Tekm
*/

#ifndef MY_H_
# define MY_H_

char            *base(unsigned char nb, int basenb, char *base);
char		*my_revstr(char *str);
int		my_strlen(char *str);
void		my_putchar(char c);
void		my_put_nbr(int nb);
void		my_putstr(char *str);
char		*my_strnbr(int nb, char *str);
int		my_getnbr(char *str);
int		binary_convert(int num);
void            send_pid(char *res, int pid);
void            do_opt(char *res, int pid);
void            my_msg();

#endif /* !MY_H_ */

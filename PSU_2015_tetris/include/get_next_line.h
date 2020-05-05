/*
** get_next_line.h for get_next_line in /home/leroy_0/rendu/CPE_2015_getnextline
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Jan  4 09:50:22 2016 leroy_0
** Last update Sat Mar 19 15:38:06 2016 Tekm
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef READ_SIZE
# define READ_SIZE (14)
#endif /* !READ_SIZE */

char	*get_next_line(const int fd);
void    my_putchar(char c);
void    my_putstr(char *str);
int     my_strlen(char *str);
char    *my_revstr(char *str);
int     my_getnbr(char *str);
int	str_verify(char *str);

typedef struct	s_struct
{
  char		**map;
  int		player;
  int		line;
  int		nb_matches;
}		t_struct;

#endif /* !GET_NEXT_LINE_H */

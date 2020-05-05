/*
** get_next_line.h for get_next_line.h in /media/klein_h/A2BC25B6BC2585BF/CPE_2015_getnextline
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Mon Jan  4 09:47:18 2016 Arthur Klein
** Last update Sun Jun  5 21:23:27 2016 bruere_s
*/

#ifndef			GET_NEXT_LINE_H_
# define		GET_NEXT_LINE_H_

#ifndef			READ_SIZE
# define		READ_SIZE (14)
#endif			/* !READ_SIZE */

typedef struct		s_list
  {
    char		data;
    char		*string;
    struct s_list	*next;
  }			t_list;

 char			*get_next_line(const int fd);
t_list			*my_put_in_list(t_list *string, char data);
char			*list_to_char(t_list **string, int j);
void			my_free_end(t_list **string);
int			end_or_size(t_list *string, int j);

#endif			/* !GET_NEXT_LINE_H_ */

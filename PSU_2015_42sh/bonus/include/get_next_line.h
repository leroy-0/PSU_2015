/*
** get_next_line.h for get_next_line in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:52:17 2016 leroy_0
** Last update Sun Jun  5 18:52:21 2016 leroy_0
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (14)
#endif /* !READ_SIZE */

typedef struct  s_list
  {
    char          data;
    char 		*string;
    struct s_list *next;
  }               t_list;

 char 			*get_next_line(const int fd);
t_list			*my_put_in_list(t_list *string, char data);
char 			*list_to_char(t_list **string, int j);
void			my_free_end(t_list **string);
int 			end_or_size(t_list *string, int j);

#endif /* !GET_NEXT_LINE_H_ */

/*
** structure.h for structure in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Dec  3 12:49:20 2015 leroy_0
** Last update Thu Dec 10 09:54:57 2015 leroy_0
*/

#ifndef STRUCTURE_H_
# define STRUCTURE_H_

typedef struct s_struct
{
  WINDOW	*w;
  char	**list;
  char	**new_list;
  char	**str;
  int	total;
  char	*item;
  int	ch;
  int	i;
  int	rowx;
  int	coly;
  int	col;
  int	line;
  int	maxcol;
  int	*choose;
  int	*new_choose;
}t_struct;

#endif /* !STRUCTURE_H_ */

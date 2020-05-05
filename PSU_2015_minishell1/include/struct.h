/*
** structure.h for structure in /home/leroy_0/rendu/CPE_2015_BSQ
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Dec 10 20:34:35 2015 leroy_0
** Last update Fri Dec 18 08:08:26 2015 leroy_0
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct	s_struct_data
{
  char	*buffer;
  int	**tab;
  char	*filepath;
  int	*savecol;
  int	*savefinal;
  int	line;
  int	maxline;
}		t_struct_data;

typedef struct  s_struct_value
{
  int	cpt;
  int	row;
  int	count;
  int	yes;
}		t_struct_value;

typedef struct  s_struct_save
{
  int   saverow;
  int   savecpt;
  int   prevrow;
  int   prevcpt;
  int	max;
  int	positionx;
  int	positiony;
}		t_struct_save;

#endif /* !STRUCT_H_ */

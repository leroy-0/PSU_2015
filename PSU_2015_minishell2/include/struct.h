/*
** struct.h for struct.h in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:29:02 2016 leroy_0
** Last update Thu Apr 21 10:29:07 2016 leroy_0
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

typedef struct  s_pipe
{
  char		***cmds;
  char          **args;
  int           nbpipe;
  int           nbarg;
  int		cpt;
  int		cpt_c;
  int		cpt_a;
  int		*fd;
  int		fdin;
  int		check;
}               t_pipe;

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

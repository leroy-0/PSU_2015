/*
** structure.h for structure in /home/leroy_0/rendu/PSU_2015_my_exec
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan  7 16:17:38 2016 leroy_0
** Last update Mon Jan 25 11:24:42 2016 leroy_0
*/

#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <signal.h>

typedef struct	s_struct_d
{
  int		nbarg;
  char		**args;
  char		**envtab;
  char		**tmpenv;
  char		*thisenv;
  int		pid;
}		t_struct_d;

# endif /* !STRUCTURE_H */

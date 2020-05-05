/*
** structure.h for structure in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:28:47 2016 leroy_0
** Last update Thu Apr 21 10:28:52 2016 leroy_0
*/

#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

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

/*
** finder.c for finder in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:56:26 2016 leroy_0
** Last update Thu Apr 21 10:03:51 2016 leroy_0
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"
#include "get_next_line.h"
#include "structure.h"

int             my_finder_antes(t_struct_d *data, char **arg, int fd)
{
  int           b;

  b = 0;
  if (arg && arg[0] && ((arg[0][0] == '.' && arg[0][1] == '/')
			|| arg[0][0] == '/'))
    return (-1);
  else
    fd = my_which_find(data, arg, fd, b);
  return (fd);
}

/*
** finder.c for finder in /home/leroy_0/rendu/PSU_2015_minishell1/src
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Jan 26 01:40:37 2016 leroy_0
** Last update Tue Jan 26 01:50:53 2016 leroy_0
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
#include "../include/my.h"
#include "../get_next_line/get_next_line.h"
#include "../include/structure.h"

int             my_finder_antes(t_struct_d *data, char **arg, int fd)
{
  int           b;

  b = 0;
  if ((arg[0][0] == '.' && arg[0][1] == '/')
      || arg[0][0] == '/')
    return (-1);
  else
    fd = my_which_find(data, arg, fd, b);
  return (fd);
}

/*
** client.c for client.c in /home/leroy_0/rendu/PSU_2015_minitalk
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Feb  1 17:29:02 2016 leroy_0
** Last update Sun Feb 21 18:54:42 2016 Tekm
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

char		*send_that_pid(char *res, int pid)
{
  char		*tmp;
  int		s_pid;
  int		cpt;

  cpt = 0;
  tmp = malloc(sizeof(char) * 8);
  s_pid = getpid();
  tmp = my_strnbr(s_pid, tmp);
  while (tmp[cpt] != '\0')
    {
      res = base(tmp[cpt], 2, "01");
      send_pid(res, pid);
      free(res);
      cpt++;
    }
  free(tmp);
  res = base('\n', 2, "01");
  send_pid(res, pid);
  free(res);
  return (res);
}

void            my_getmsg(int pid, char *msg)
{
  char		*res;
  int		cpt;

  res = NULL;
  cpt = 0;
  res = send_that_pid(res, pid);
  while (msg[cpt] != '\0')
    {
      res = base(msg[cpt], 2, "01");
      do_opt(res, pid);
      free(res);
      cpt++;
    }
  res = base('\0', 2, "01");
  do_opt(res, pid);
}

int		main(int ac, char **av)
{
  (void)ac;

  if (signal(SIGUSR1, my_msg) == SIG_ERR)
    my_putstr("ERROR IN SIGNAL\n");
  if (ac == 3)
    {
      if (my_getnbr(av[1]) >= 1)
	my_getmsg(my_getnbr(av[1]), av[2]);
      else
	{
	  my_putstr("Usage: ./client PID MSG\n");
	  return (1);
	}
    }
  else
    {
      my_putstr("Usage: ./client PID MSG\n");
      return (1);
    }
  return (0);
}

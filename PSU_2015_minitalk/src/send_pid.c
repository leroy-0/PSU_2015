/*
** send_pid.c for send_pid in 
** 
** Made by Tekm
** Login   <tekm@epitech.net>
** 
** Started on  Sun Feb 21 18:44:08 2016 Tekm
** Last update Sun Feb 21 18:52:36 2016 Tekm
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/my.h"

int		ctrl;

void            my_msg()
{
  ctrl = 0;
}

void            send_pid(char *res, int pid)
{
  int           a;

  a = 0;
  while (res && res[a] != '\0')
    {
      if (res[a] == '0' && res[a] != '\0')
        {
          kill(pid, SIGUSR1);
          a++;
        }
      else if (res[a] == '1' && res[a] != '\0')
        {
          kill(pid, SIGUSR2);
          a++;
        }
      usleep(5000);
    }
}

void            do_opt(char *res, int pid)
{
  int           a;

  a = 0;
  while (res[a] && a <= 7)
    {
      if (res[a] == '0' && res[a] != '\0' && ctrl == 0)
        {
          ctrl = 1;
          a++;
          kill(pid, SIGUSR1);
        }
      else if (res[a] == '1' && res[a] != '\0' && ctrl == 0)
        {
          ctrl = 1;
          a++;
          kill(pid, SIGUSR2);
        }
    }
}

/*
** server.c for server.c in /home/leroy_0/rendu/PSU_2015_minitalk
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Feb  1 18:23:07 2016 leroy_0
** Last update Sun Feb 21 18:30:37 2016 Tekm
*/

#include	<sys/types.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../include/my.h"

int		cstart = 0;

int		my_get_pid(char *car)
{
  static char	tmp[10];
  static int	b = 0;
  int		pid;
  int		nb;

  nb = binary_convert(my_getnbr(car));
  if (nb == '\n')
    {
      tmp[b] = '\0';
      pid = my_getnbr(tmp);
      b = 0;
      cstart = 1;
      return (pid);
    }
  else
    {
      tmp[b] = nb;
      b++;
    }
  return (0);
}

int		get_that_pid(int msg, int pid)
{
  static char	res[9];
  static int	a = 0;

  if (msg == 0)
    res[a] = '0';
  else
    res[a] = '1';
  a++;
  if (a > 7)
    {
      pid = my_get_pid(res);
      a = 0;
    }
  return (pid);
}

void		ping_pong(int msg, int pid)
{
  static char	car[9];
  static int	cpt = 0;
  int		nb;

  if (msg == 0)
    car[cpt] = '0';
  else
    car[cpt] = '1';
  cpt++;
  if (cpt > 7)
    {
      nb = binary_convert(my_getnbr(car));
      if (nb == 0)
	{
	  my_putchar('\n');
	  cstart = 0;
	}
      else
	my_putchar(nb);
      cpt = 0;
    }
  kill(pid, SIGUSR1);
}

void		my_msg(int sig)
{
  static int	pid = 0;
  int		msg = 0;

  if (sig == SIGUSR1)
    msg = 0;
  else if (sig == SIGUSR2)
    msg = 1;
  if (cstart == 0)
    pid = get_that_pid(msg, pid);
  else if (cstart == 1)
    ping_pong(msg, pid);

}

int		main(int ac, char **av)
{
  (void)ac;
  (void)av;

  my_put_nbr(getpid());
  my_putchar('\n');
  if (signal(SIGUSR1, my_msg) == SIG_ERR
      || signal(SIGUSR2, my_msg) == SIG_ERR)
    my_putstr("ERROR IN SIGNAL\n");
  while (1)
    pause();
  return (0);
}

/*
** exit.c for exit in /home/leroy_0/tek1/PSU_2015_42sh/built-in/exit
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed May  4 08:12:12 2016 leroy_0
** Last update Sun Jun  5 23:31:45 2016 bruere_s
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"bonus.h"
#include	"exec.h"
#include	"my.h"

char		**my_exit(char *str, char **env)
{
  (void) (env);
  if (isatty(0) != 0)
    my_putstr("exit\n");
  if (str != NULL && str[0] != '\0')
    {
      if (str != NULL && my_getnbr(str) >= 0 && my_getnbr(str) <= 255)
	exit(my_getnbr(str));
      else
	exit(0);
    }
  else if (str == NULL)
    exit(0);
  return (NULL);
}

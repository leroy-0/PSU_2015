/*
** echo_special_func.c for echo in /home/bruere_s/Projet/PSU_2015_42sh/built-in/echo
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Fri Jun  3 17:09:17 2016 bruere_s
** Last update Fri Jun  3 20:42:54 2016 bruere_s
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<string.h>
#include	"my.h"

char		*echo_O_special(char *s)
{
  s = strdup("42sh");
  return (s);
}

char		*echo_dollard_special(char *s)
{
  char		*tmp;

  (void) s;
  tmp = my_itoa(getppid());
  return (tmp);
}

char		*echo_excla_special(char *s)
{
  return (s);
}

/*
** check.c for check.c in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:21:25 2016 leroy_0
** Last update Thu Apr 21 10:27:01 2016 leroy_0
*/

#include "my.h"

int             check_strrandom(char *str)
{
  int           cpt;

  cpt = 0;
  while (str && str[cpt])
    {
      if (str[cpt] > 126 || str[cpt] < 0)
	{
	  my_putstr(str);
	  my_putstr(" : Unable to find the command\n");
	  return (1);
	}
      cpt++;
    }
  return (0);
}

/*
** my_putstr.c for my_putstr in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:01:26 2015 sebastien bruere
** Last update Mon Nov 23 17:17:54 2015 Sebastien BRUERE
*/

#include <unistd.h>
#include "../../include/my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

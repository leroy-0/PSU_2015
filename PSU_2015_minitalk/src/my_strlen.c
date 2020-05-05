/*
** my_strlen.c for my_strlen in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 13:45:25 2015 maxime leroy
** Last update Sat Feb 20 19:35:37 2016 Tekm
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int z;

  z = 0;
  if (str == NULL)
    return (0);
  while (str && str[z] != '\0')
    z += 1;
  return (z);
}

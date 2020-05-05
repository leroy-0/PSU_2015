/*
** my_strlen.c for my_strlen in /home/leroy_0/rendu/j_04
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Oct  1 13:45:25 2015 maxime leroy
** Last update Mon Jan 18 16:38:44 2016 leroy_0
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int z;

  z = 0;
  if (str == NULL)
    return (0);
  while (str[z] != '\0')
    {
      z = z + 1;
    }
  return (z);
}

/*
** my_revstr.c for my_revstr in /home/bruere_s/rendu/Piscine_C_J06
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Mon Oct  5 13:52:13 2015 sebastien bruere
** Last update Wed Jan 13 15:59:26 2016 Sebastien BRUERE
*/

#include "../../include/my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	i2;
  char	tmp;

  i = 0;
  i2 = my_strlen(str) - 1;
  while (i < i2)
    {
      tmp = str[i];
      str[i] = str[i2];
      str[i2] = tmp;
      i++;
      i2--;
    }
  return (str);
}

/*
** my_strcat.c for my_strcat in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Fri Oct  9 12:14:12 2015 sebastien bruere
** Last update Thu Nov  5 09:42:41 2015 Sebastien BRUERE
*/

#include "../../include/my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	i2;

  i = my_strlen(dest);
  i2 = 0;
  while (src[i2] != '\0')
    {
      dest[i] = src[i2];
      i++;
      i2++;
    }
  dest[i] = '\0';
  return (dest);
}

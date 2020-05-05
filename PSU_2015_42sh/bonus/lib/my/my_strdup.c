/*
** my_strdup.c for my_strdup in /home/bruere_s/rendu/Piscine_C_J08
**
** Made by sebastien bruere
** Login   <bruere_s@epitech.net>
**
** Started on  Wed Oct  7 09:56:40 2015 sebastien bruere
** Last update Sun Jun  5 23:22:56 2016 longle_h
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*my_strdup(char *src)
{
  char	*copy;
  int	i;

  i = 0;
  copy = my_x_malloc(sizeof(char) * my_strlen(src));
  while (src[i] != '\0')
    {
      copy[i] = src[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

/*
** epur_str.c for epur_str in /home/leroy_0/rendu/PSU_2015_minishell1
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Jan 25 12:24:59 2016 leroy_0
** Last update Mon Jan 25 13:01:23 2016 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char            *epur_str(char *str)
{
  char          *res;
  int           x;
  int           y;

  x = 0;
  y = 0;
  if ((res = malloc(sizeof(res) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[x] == ' ' || str[x] == '	')
    x++;
  while (str[x])
    {
      if (str[x] == ' ' || str[x] == '	')
        {
          res[y++] = ' ';
          while (str[x] == ' ' || str[x] == '	')
            x++;
        }
      res[y++] = str[x++];
    }
  res[y] = '\0';
  if (res[y - 1] == ' ' || res[y - 1] == '	')
    res[y - 1] = '\0';
  return (res);
}

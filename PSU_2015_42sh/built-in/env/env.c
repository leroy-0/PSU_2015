/*
** env.c for env in /home/leroy_0/tek1/PSU_2015_42sh/built-in/env
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri May  6 12:24:49 2016 leroy_0
** Last update Wed May 18 15:48:40 2016 longle_h
*/

#include	<stdio.h>
#include	"my.h"

char		**my_env(char *str, char **env)
{
  int		cpt;

  (void)str;
  cpt = 0;
  while (env && env[cpt])
    {
      my_putstr(env[cpt]);
      my_putchar('\n');
      cpt++;
    }
  return (env);
}

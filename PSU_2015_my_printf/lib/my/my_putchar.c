/*
** my_putchar.c for my_putchar in /home/leroy_0/rendu/Piscine_C_J07/lib/my
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Oct  6 12:40:13 2015 maxime leroy
** Last update Thu Nov 12 22:04:31 2015 leroy_0
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

/*
** my_putchar.c for my_putchar in /home/leroy_0/rendu/PSU_2015_minitalk
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Tue Feb  2 00:17:53 2016 leroy_0
** Last update Tue Feb  2 00:18:32 2016 leroy_0
*/

#include "unistd.h"

void            my_putchar(char c)
{
  write(1, &c, 1);
}

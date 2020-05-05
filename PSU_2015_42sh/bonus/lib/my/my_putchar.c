/*
** my_putchar.c for my_putchar in /home/bruere_s/Projet/CPE_2015_BSQ/lib/my
**
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
**
** Started on  Mon Nov 30 17:11:04 2015 Sebastien BRUERE
** Last update Mon Mar 21 18:16:13 2016 Sebastien BRUERE
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

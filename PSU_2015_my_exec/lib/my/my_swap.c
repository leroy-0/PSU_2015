/*
** my_swap.c for my_swap in /home/leroy_0/rendu/j_04
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Thu Oct  1 11:08:24 2015 maxime leroy
** Last update Thu Oct  1 12:28:50 2015 maxime leroy
*/

int	my_swap(int *a, int *b)
{
  int z;

  z = *a;
  *a = *b;
  *b = z;
}

/*
** my_power_rec.c for my_power_rec in /home/leroy_0/rendu/J_05
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Fri Oct  2 17:15:38 2015 maxime leroy
** Last update Fri Oct  9 14:09:13 2015 maxime leroy
*/

int     my_power_rec(int nb, int power)
{
  int a;

  a = 1;
  if (power < 0)
    {
      return (0);
    }
  if (power != 0)
    {
      a = my_power_rec(nb, power - 1);
      a = a * nb;
    }
  return (a);
}

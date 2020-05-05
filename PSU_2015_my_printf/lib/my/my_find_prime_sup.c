/*
** my_is_prime.c for my_is_prime in /home/leroy_0/rendu/Piscine_C_J05
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 13:36:38 2015 maxime leroy
** Last update Tue Oct  6 14:17:59 2015 maxime leroy
*/

int     my_find_prime_sup(int nb)
{
  int a;
  int c;

  a = 2;
  if (nb == 0 || nb == 1)
      return (0);
  while (a < nb)
    {
      if (nb % a == 0)
	{
	  return (nb + 1);
	}
      a = a + 1;
    }
  c = 1;
  if (c == 1)
    return (a);
}

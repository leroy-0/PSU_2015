/*
** my_find_prime_sup.c for my_find_prime_sup in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:49:35 2016 leroy_0
** Last update Thu Apr 21 09:49:40 2016 leroy_0
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
  return (0);
}

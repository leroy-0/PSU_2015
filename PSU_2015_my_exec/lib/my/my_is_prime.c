/*
** my_is_prime.c for my_is_prime in /home/leroy_0/rendu/Piscine_C_J05
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 13:36:38 2015 maxime leroy
** Last update Wed Oct  7 17:34:22 2015 maxime leroy
*/

int     my_is_prime(int nombre)
{
  int   a;

  a = 2;
  if (nombre == 0 || nombre == 1)
      return (0);
  while (a < nombre)
    {
      if (nombre % a == 0)
          return (0);
      a = a + 1;
    }
  return (1);
}

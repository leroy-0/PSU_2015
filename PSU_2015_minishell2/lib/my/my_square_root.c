/*
** my_square_root.c for my_square_root in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:50:04 2016 leroy_0
** Last update Thu Apr 21 09:50:27 2016 leroy_0
*/

int	my_square_root(int nb)
{
  int a;

  a = 1;
  if (nb == 0 || nb < 0)
    return (0);
  while ((a*a) != nb && a < 46341)
    a++;
  if (a > 46340)
    return ('\0');
  if (a * a == nb)
    return (a);
  return (0);
}

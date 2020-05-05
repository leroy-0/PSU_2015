/*
** my_getnbr.c for my_getnbr in /home/leroy_0/rendu/Piscine_C_J04
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 12:45:17 2015 maxime leroy
** Last update Wed Oct  7 17:32:28 2015 maxime leroy
*/

int	my_getnbr(char *str)
{
  int a;
  int b;

  a = 1;
  b = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	a = - a;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (b > 214748364)
	return (0);
      if (b == 214748364 && *str > 7 && a == 1)
	return (0);
      if (b == 214748364 && *str > 8 && a == -1)
	return (0);
      b = b * 10 + *str - 48;
      str = str + 1;
    }
  if (a == -1)
    b = - b;
  return (b);
}

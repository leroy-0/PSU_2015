/*
** my_str_isprintable.c for my_str_isprintable in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 13:05:02 2015 maxime leroy
** Last update Sat Oct 17 20:02:21 2015 maxime leroy
*/

int	my_str_isprintable(char *str)
{
  int	a;

  a = 0;
  while (a != sizeof(str))
    {
      if (str[a] >= 32 && str[a] <= 126)
	a++;
      else
	return (0);
    }
  return (1);
}

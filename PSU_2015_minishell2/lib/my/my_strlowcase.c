/*
** my_strlowcase.c for my_strlowcase in /home/leroy_0/rendu/Piscine_C_J06/ex_09
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 17:47:42 2015 maxime leroy
** Last update Thu Apr 21 09:47:18 2016 leroy_0
*/

char    *my_strlowcase(char *str)
{
  int		a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= 'Z' && str[a] >= 'A')
	str[a] = str[a] + 32;
      if (str[a] > 'Z' || str[a] < 'A')
	str[a] = str[a];
      a++;
    }
  return (str);
}

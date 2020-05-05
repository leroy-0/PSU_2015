/*
** my_strlowcase.c for my_strlowcase in /home/leroy_0/rendu/Piscine_C_J06/ex_09
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 17:47:42 2015 maxime leroy
** Last update Tue Oct  6 17:52:25 2015 maxime leroy
*/

char    *my_strlowcase(char *str)
{
  char a;

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

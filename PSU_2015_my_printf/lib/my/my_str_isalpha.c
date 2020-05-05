/*
** my_str_isalpha.c for my_str_isalpha in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 12:59:24 2015 maxime leroy
** Last update Fri Oct 16 13:53:34 2015 maxime leroy
*/

int	my_str_isalpha(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= 'z' && str[a] >= 'a' || str[a] < 'Z' && str[a] > 'A')
	a++;
      else
	return (0);
    }
  if (str[a] == '\0')
    return (1);
}

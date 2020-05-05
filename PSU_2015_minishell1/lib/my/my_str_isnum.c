/*
** my_str_isnum.c for my_str_isnum in /home/leroy_0/rendu/Piscine_C_workshoplib
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Fri Oct 16 13:46:51 2015 maxime leroy
** Last update Fri Oct 16 13:50:26 2015 maxime leroy
*/

int	my_str_isnum(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= '9' && str[a] >= '0')
	a++;
      else
	return (0);
    }
  if (str[a] == '\0')
    return (1);
}

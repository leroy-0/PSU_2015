/*
** my_strcmp.c for my_strcmp in /home/leroy_0/rendu/Piscine_C_J06/ex_06
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 15:21:44 2015 maxime leroy
** Last update Tue Mar 15 12:55:42 2016 Tekm
*/

int	my_strcmp(char *s1, char *s2)
{
  int   a;

  a = 0;
  while (s2[a])
    {
      if (s1[a] < s2[a])
	return (-1);
      if (s1[a] > s2[a])
	return (1);
      a++;
    }
  if (s1[a] < s2[a])
    return (-1);
  if (s1[a] > s2[a])
    return (1);
  if (s2[a] == s1[a])
    return (0);
  return (0);
}

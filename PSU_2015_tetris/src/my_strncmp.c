/*
** my_strncmp.c for my_strncmp in /home/leroy_0/rendu/Piscine_C_J06/ex_07
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 16:30:48 2015 maxime leroy
** Last update Thu Mar 17 21:38:49 2016 Tekm
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int a;

  a = 0;
  while (a < nb - 1)
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

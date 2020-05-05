/*
** my_strncmp.c for my_strncmp in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:47:45 2016 leroy_0
** Last update Thu Apr 21 09:47:51 2016 leroy_0
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int a;

  a = 0;
  while (a < nb)
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

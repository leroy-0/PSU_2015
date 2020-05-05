/*
** my_strcmp.c for my_strcmp in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:48:11 2016 leroy_0
** Last update Thu Apr 21 09:48:22 2016 leroy_0
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

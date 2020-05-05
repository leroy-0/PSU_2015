/*
** my_strcmp.c for my_strcmp in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:52:23 2016 leroy_0
** Last update Sun Jun  5 17:52:54 2016 leroy_0
*/

int		my_strcmp(char *s1, char *s2)
{
  int		a;

  a = 0;
  while (s1 && s1[a])
    {
      if (s1[a] < s2[a])
	return (-1);
      if (s1[a] > s2[a])
	return (1);
      a++;
    }
  return (0);
}

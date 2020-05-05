/*
** my_strcmp.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/lib/my/my_strcmp.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:09:24 2016 Arthur KLEIN
** Last update Sat Jun 04 19:09:24 2016 Arthur KLEIN
*/

int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a])
    {
      if (s1[a] < s2[a])
	return (-1);
      if (s1[a] > s2[a])
	return (1);
      a++;
    }
  return (0);
}
/*
** my_strcat.c for my_strcat in /home/leroy_0/rendu/Piscine_C_J07/lib/my
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Oct  7 13:08:47 2015 maxime leroy
** Last update Fri Mar 18 18:55:11 2016 Tekm
*/

char    *my_strcat(char *dest, char *src)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (dest && dest[a] != '\0')
    a++;
  while (src && src[b] != '\0')
    {
      dest[a + b] = src[b];
      b++;
    }
  dest[a + b] = '\0';
  return (dest);
}

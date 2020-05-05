/*
** my_strcpy.c for my_strcpy in /home/leroy_0/rendu/j_06
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Oct  5 09:17:15 2015 maxime leroy
** Last update Sun Jan 24 17:26:28 2016 leroy_0
*/

char	*my_strcpy(char *dest, char *src)
{
  int x;

  x = 0;
  while (src && src[x] != '\0')
    {
      dest[x] = src[x];
      x++;
    }
  dest[x] = '\0';
  return (dest);
}

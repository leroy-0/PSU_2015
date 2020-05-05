/*
** my_strcpy.c for my_strcpy in /home/leroy_0/rendu/j_06
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Mon Oct  5 09:17:15 2015 maxime leroy
** Last update Fri Mar 18 18:53:25 2016 Tekm
*/

char	*my_strcpy(char *dest, char *src)
{
  int x;

  x = 0;
  while (src[x] != '\0')
    {
      dest[x] = src[x];
      x++;
    }
  dest[x] = '\0';
  return (dest);
}

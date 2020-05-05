/*
** my_strncat.c for my_strncat in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 13:09:40 2015 maxime leroy
** Last update Fri Oct 16 13:54:08 2015 maxime leroy
*/

int	my_nbsup(char *dest, char *src, int nb)
{
  char a;
  char b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    a++;
  if (nb <= sizeof(src))
    {
      while (b != nb)
	{
	  dest[a] = src[b];
	  a++;
	  b++;
	}
      dest[a] = '\0';
    }
}

int	my_nbinf(char *dest, char *src, int nb)
{
  char a;
  char b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    a++;
  if (nb > sizeof(src))
    {
      while (b != sizeof(src))
	{
	  dest[a] = src[b];
	  a++;
	  b++;
	}
      dest[a] = src[a];
    }
}

char	*my_strncat(char *dest, char *src, int nb)
{
  my_nbsup(dest, src, nb);
  my_nbinf(dest, src, nb);
  return (dest);
}

/*
** my_strstr.c for my_strstr in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:48:36 2016 leroy_0
** Last update Thu Apr 21 09:49:10 2016 leroy_0
*/

char	*my_strstr(char *str, char *to_find)
{
  int a;
  int b;

  a = 0;
  b = 0;
  while (to_find[b] != '\0')
    {
      while (str[a] != to_find[0])
	a++;
      if (str[a] == to_find[b])
	while (str[a++] == to_find[b])
	  b++;
      if (to_find[b] == '\0')
	{
	  a = a - (b + 1);
	  return (str + a);
	}
      if (str[a] == '\0')
	return ('\0');
      b = 0;
    }
  return ('\0');
}

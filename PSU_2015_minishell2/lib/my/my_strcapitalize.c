/*
** my_strcapitalize.c for my_strcapitalize in 
** 
** Made by leroy_0
** Login   <leroy_0@epitech.net>
** 
** Started on  Thu Apr 21 09:46:45 2016 leroy_0
** Last update Thu Apr 21 09:47:00 2016 leroy_0
*/

char	*my_strcapitalize(char *str)
{
  int a;

  a = 0;
  if (str[0] >= 97 && str[0] <= 122)
    str[0] = str[0] - 32;
  while (str[a] != '\0')
    {
      if (str[a] >= 'a' && str[a] <= 'z')
	{
	  if (str[a - 1] <= 'Z' && str[a - 1] >= 'A')
	    a++;
	  else if (str[a - 1] > '9' && str[a - 1] < 'A')
	    str[a] = str[a] - 32;
	  else if (str[a - 1] < '0')
	    str[a] = str[a] - 32;
	  else if (str[a - 1] > 'z')
	    str[a] = str[a] - 32;
	  a++;
	}
      else
	a = a + 1;
    }
  return (str);
}

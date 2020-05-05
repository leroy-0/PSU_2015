/*
** my_strcapitalize.c for my_strcapitalize in /home/leroy_0/rendu/Piscine_C_J06/ex_10
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Tue Oct  6 17:54:10 2015 maxime leroy
** Last update Fri Oct  9 14:11:08 2015 maxime leroy
*/

char	*my_strcapitalize(char *str)
{
  int a;
  int i;

  a = 0;
  i = 1;
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

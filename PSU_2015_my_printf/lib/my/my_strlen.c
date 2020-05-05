/*
** my_strlen.c for my_strlen in /home/leroy_0/rendu/j_04
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Thu Oct  1 13:45:25 2015 maxime leroy
** Last update Thu Oct  1 16:36:18 2015 maxime leroy
*/

int	my_strlen(char *str)
{
  int z;

  z = 0;
  while (str[z] != '\0')
    {
      z = z + 1;
    }
  return (z);
}

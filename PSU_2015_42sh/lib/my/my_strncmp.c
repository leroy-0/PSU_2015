/*
** my_strncmp.c for my_strncmp in /home/bruere_s/Test
** 
** Made by Sebastien BRUERE
** Login   <sebastien.bruere@epitech.eu>
** 
** Started on  Sun Oct 18 16:54:04 2015 Sebastien BRUERE
** Last update Sun Oct 18 16:54:30 2015 Sebastien BRUERE
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s2[i] != '\0' && i < n)
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}


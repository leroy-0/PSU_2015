/*
** my_sort_int_tab.c for my_sort_int_tab in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 12:21:15 2015 maxime leroy
** Last update Sun Oct 18 14:55:23 2015 maxime leroy
*/

int	my_sort_int_tab(int *tab, int size)
{
  int   a;
  int   toto;
  int   b;

  b = 0;
  toto = 0;
  while (toto == 0)
    {
      if (toto == 0)
	{
	  a = 0;
	  toto = 1;
	  while ((a + 1) < size)
	    {
	      if (tab[a] > tab[a + 1])
		{
		  toto = 0;
		  my_swap(&tab[a], &tab[a + 1]);
		}
	      a = a + 1;
	    }
	  b++;
	}
    }
}

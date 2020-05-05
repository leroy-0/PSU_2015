/*
** echo_ptr_func_else.c for echo in /home/bruere_s/PSU_2015_42sh/built-in/echo
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Thu Jun  2 18:45:44 2016 bruere_s
** Last update Sun Jun  5 21:24:50 2016 bruere_s
*/

#include	"my.h"
#include	"built_in.h"

void		print_n_echo(void)
{
  my_putchar('\n');
}

void		print_r_echo(void)
{
  my_putchar('\r');
}

void		print_t_echo(void)
{
  my_putchar('\t');
}

void		print_v_echo(void)
{
  my_putchar('\v');
}

t_echo		*init_tab()
{
  t_echo	*tab;

  tab = my_x_malloc(sizeof(t_echo) * 8);
  tab[0].car = 'a';
  tab[0].func = &print_a_echo;
  tab[1].car = 'b';
  tab[1].func = &print_b_echo;
  tab[2].car = 'e';
  tab[2].func = &print_e_echo;
  tab[3].car = 'f';
  tab[3].func = &print_f_echo;
  tab[4].car = 'n';
  tab[4].func = &print_n_echo;
  tab[5].car = 'r';
  tab[5].func = &print_r_echo;
  tab[6].car = 't';
  tab[6].func = &print_t_echo;
  tab[7].car = 'v';
  tab[7].func = &print_v_echo;
  return (tab);
}

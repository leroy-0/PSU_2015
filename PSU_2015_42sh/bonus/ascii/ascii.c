/*
** ascii.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/bonus/ascii/ascii.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sun Jun 05 13:43:31 2016 Arthur KLEIN
** Last update Sun Jun  5 23:07:29 2016 bruere_s
*/

#include	<stdio.h>

static void	print_next_ascii(void)
{
  printf(
	 " 4::::444444::::444     22222::::::22    s::::::ssss:::::s h::::::\
:hhh::::::h \n"
	 " 4::::::::::::::::4   22::::::::222       s:::::s  ssssss  h::::::\
h   h::::::h\n"
	 " 4444444444:::::444  2:::::22222            s::::::s       h:::::h\
     h:::::h\n"
	 "           4::::4   2:::::2                    s::::::s    h:::::h\
     h:::::h\n"
	 "           4::::4   2:::::2              ssssss   s:::::s  h:::::h\
     h:::::h\n"
	 "           4::::4   2:::::2       222222 s:::::ssss::::::s h:::::h\
     h:::::h\n"
	 "         44::::::44 2::::::2222222:::::2 s::::::::::::::s  h:::::h\
     h:::::h\n"
	 "         4::::::::4 2::::::::::::::::::2  s:::::::::::ss   h:::::h \
    h:::::h\n"
	 "         4444444444 22222222222222222222   sssssssssss     hhhhhhh \
    hhhhhhh\033[0m\n"
	 "\n"
	 "  \033[31m          Made by bruere_s klein_h leroy_0 longle_h \
poinss_y\n\n \033[0m\n");
}

void		put_my_ascii()
{
  printf("\033[34m");
  printf("\n        444444444    222222222222222                       hhhhhh \
            \n"
	 "       4::::::::4   2:::::::::::::::22                     h::::h \
            \n"
	 "      4:::::::::4   2::::::222222:::::2                    h::::h \
            \n"
	 "     4::::44::::4   2222222     2:::::2                    h::::h \
            \n"
	 "    4::::4 4::::4               2:::::2      ssssssssss    h::::h \
hhhhh       \n"
	 "   4::::4  4::::4               2:::::2    ss::::::::::s   h::::hh\
:::::hhh    \n"
	 "  4::::4   4::::4            2222::::2   ss:::::::::::::s  h::::::\
::::::::hh  \n");
    print_next_ascii();
}

/*
** alias.h for alias in /home/bruere_s/Projet/PSU_2015_42sh/bonus
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 15:57:31 2016 bruere_s
** Last update Sun Jun  5 23:29:03 2016 bruere_s
*/

#ifndef		ALIAS_H_
# define	ALIAS_H_

char		**gimme_alias(void);
char		*change_variable_alias(char **alias, char *s);
int		check_good_alias(char *s, int mode);

#endif		/* !ALIAS_H_ */

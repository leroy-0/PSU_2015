/*
** cd_actions.c for cd in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Wed Jun  1 15:08:58 2016 bruere_s
** Last update Sun Jun  5 20:50:45 2016 bruere_s
*/

#include	<unistd.h>
#include	"my.h"
#include	"built_in.h"

char		**display_error_cd(char *str, int mode)
{
  if (mode == 1)
    my_puterr("Error : getcwd failed\n");
  else if (mode == 2)
    my_puterr("OLDPWD : No directory found\n");
  else if (mode == 3)
    my_puterr("HOME : No directory found\n");
  else if (mode == 4)
    {
      my_puterr(str);
      my_puterr(": Permission denied.\n");
    }
  else if (mode == 5)
    {
      my_puterr(str);
      my_puterr(": Not a directory.\n");
    }
  return (NULL);
}

char		**my_cd_oldpwd(char ***env)
{
  char		*tmp;

  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  if (chdir(my_search_env("OLDPWD", *env)) == -1)
    return (display_error_cd(NULL, 2));
  *env = my_putenv("OLDPWD", tmp, *env);
  free(tmp);
  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  *env = my_putenv("PWD", tmp, *env);
  free(tmp);
  return (*env);
}

char		**my_cd_directory(char ***env, char *str)
{
  char		*tmp;

  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  if (access(str, R_OK) == -1 && access(str, F_OK) == 0)
    return (display_error_cd(str, 4));
  if (chdir(str) == -1)
    return (display_error_cd(str, 5));
  *env = my_putenv("OLDPWD", tmp, *env);
  free(tmp);
  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  *env = my_putenv("PWD", tmp, *env);
  free(tmp);
  return (*env);
}

char		**my_cd_home(char ***env)
{
  char		*tmp;

  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  if ((my_search_env("HOME", *env) == NULL)
      || chdir(my_search_env("HOME", *env)) == -1)
    return (display_error_cd(NULL, 3));
  *env = my_putenv("OLDPWD", tmp, *env);
  free(tmp);
  tmp = my_x_malloc(sizeof(char) * MAX_PATH_LEN);
  if (getcwd(tmp, MAX_PATH_LEN) == NULL)
    return (display_error_cd(NULL, 1));
  *env = my_putenv("PWD", tmp, *env);
  free(tmp);
  return (*env);
}

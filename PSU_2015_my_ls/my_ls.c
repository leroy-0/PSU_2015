/*
** info_file.c for info_file in /home/leroy_0/rendu/PSU_2015_my_ls_bootstrap
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Nov 19 14:18:13 2015 leroy_0
** Last update Sat Nov 28 00:52:16 2015 leroy_0
*/

#define _BSD_SOURCE
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "include/my.h"

char	*my_pathname(struct dirent *file_read, char *my_dir)
{
  char	*pathname;

  pathname = malloc(sizeof(char) * (my_strlen(my_dir)
				    + my_strlen(file_read->d_name) + 2));
  my_strcpy(pathname, my_dir);
  pathname[my_strlen(my_dir)] = '\0';
  if (pathname[my_strlen(pathname) - 1] != '/')
    my_strcat(pathname, "/");
  pathname[my_strlen(my_dir)] = '\0';
  my_strcat(pathname, file_read->d_name);
  pathname[my_strlen(my_dir) + my_strlen(file_read->d_name)] = '\0';
  return (pathname);
}

char	*my_display_condition(char *str, char *my_name, int a, int b)
{
  while (str[a] != '/' && str[a] != '.')
    {
      my_name[b] = str[a];
      a--;
      b++;
    }
  my_name = my_revstr(my_name);
  my_name[b] = '\0';
  return (my_name);
}

char	*my_display_previous(char *str, char *my_dir, int a, int b)
{
  int	c;

  c = 0;
  b = 0;
  a = my_strlen(str) - 1;
  while (c != 1)
    {
      while (str[a] != '/' && str[a] != '.')
	a--;
      if (str[a] == '.' && str[a - 1] != '.')
	a--;
      else
	c = 1;
    }
  while (str[a])
    {
      my_dir[b] = str[a];
      a--;
      b++;
    }
  my_dir = my_revstr(my_dir);
  my_dir[b] = '\0';
  return (my_dir);
}
char	*my_display_condition2(char *str, char *my_name, int a, int b)
{
  while (str[a] != '/' && a <= 0)
    {
      my_name[b] = str[a];
      a--;
      b++;
    }
  my_name = my_revstr(my_name);
  my_name[b] = '\0';

  return (my_name);
}

char	*my_display_previous2(char *str, char *my_dir, int a, int b)
{
  b = 0;
  a = my_strlen(str) - 1;
  while (str[a])
    {
      my_dir[b] = str[a];
      a--;
      b++;
    }
  my_dir = my_revstr(my_dir);
  my_dir[b] = '\0';
  return (my_dir);
}

void	my_display_type(struct stat *file_info)
{
  if (S_ISDIR(file_info->st_mode))
    my_putstr("d");
  else if (S_ISLNK(file_info->st_mode))
    my_putstr("l");
  else if (S_ISCHR(file_info->st_mode))
    my_putstr("c");
  else if (S_ISBLK(file_info->st_mode))
    my_putstr("b");
  else if (S_ISFIFO(file_info->st_mode))
    my_putstr("p");
  else if (S_ISSOCK(file_info->st_mode))
    my_putstr("s");
  else
    my_putstr("-");
}

void	my_previous_time(char *time, char *buffer, int a, int b)
{
  while (buffer[a] != ':')
    {
      time[b] = buffer[a];
      b++;
      a++;
    }
  time[b] = buffer[a];
  a++;
  b++;
  while (buffer[a] != ':')
    {
      time[b] = buffer[a];
      b++;
      a++;
    }
  time[b] = '\0';
  my_putstr(time);
}

void	my_time(struct stat *file_info)
{
  char *buffer;
  char *time;
  int	a;
  int	b;

  a = 0;
  b = 0;
  buffer = malloc(30 * sizeof(char));
  time = malloc(30 * sizeof(char));
  buffer = ctime(&file_info->st_mtime);
  while (buffer[a] != ' ')
    a++;
  a++;
  while (buffer[a] != ' ')
    {
      time[b] = buffer[a];
      b++;
      a++;
    }
  my_previous_time(time, buffer, a, b);
}

void	my_condition_of_rights(struct stat *file_info)
{
  my_display_type(file_info);
  my_putstr((file_info->st_mode&S_IRUSR) ? "r" : "-");
  my_putstr((file_info->st_mode&S_IWUSR) ? "w" : "-");
  if (file_info->st_mode&S_IXUSR)
    my_putstr("x");
  if (file_info->st_mode&S_ISUID)
    my_putstr("S");
  if (file_info->st_mode&S_ISUID || file_info->st_mode&S_IXUSR)
    {
    }
  else
    my_putchar('-');
  my_putstr((file_info->st_mode&S_IRGRP) ? "r" : "-");
  my_putstr((file_info->st_mode&S_IWGRP) ? "w" : "-");
  if (file_info->st_mode&S_IXGRP)
    my_putstr("x");
  if (file_info->st_mode&S_ISGID)
    my_putstr("S");
  if (file_info->st_mode&S_ISGID || file_info->st_mode&S_IXGRP)
    {
    }
  else
    my_putchar('-');
  my_putstr((file_info->st_mode&S_IROTH) ? "r" : "-");
  my_putstr((file_info->st_mode&S_IWOTH) ? "w" : "-");
  my_putstr((file_info->st_mode&S_IXOTH) ? "x" : "-");
}

void	my_rights(struct stat *file_info, char *str, struct dirent *file_read,
		  char *my_dir)
{
  struct passwd *pwd;
  struct group *grp;
  char linkname[1024];
  int r;

  my_condition_of_rights(file_info);
  my_putchar(' ');
  my_put_nbr(file_info->st_nlink);
  pwd = getpwuid(file_info->st_uid);
  my_putchar(' ');
  my_putstr(pwd->pw_name);
  grp = getgrgid(file_info->st_gid);
  my_putchar(' ');
  my_putstr(grp->gr_name);
  my_putchar(' ');
  my_put_nbr(file_info->st_size);
  my_putchar(' ');
  my_time(file_info);
  my_putchar(' ');
  my_putstr(str);
  lstat(my_pathname(file_read, my_dir), file_info);
  if (S_ISLNK(file_info->st_mode))
    {
      r = readlink(my_pathname(file_read, my_dir), linkname,
		   file_info->st_size + 1);
      my_putstr(" -> ");
      linkname[r] = '\0';
      my_putstr(linkname);
    }
}

void	my_lsl(DIR* dir_p, struct stat file_info, struct dirent *file_read)
{
  int total;

  total = 0;
  dir_p = opendir(".");
  while ((file_read = readdir(dir_p)) != NULL)
    {
      lstat(file_read->d_name, &file_info);
      if (file_read->d_name[0] != '.')
	total += file_info.st_blocks / 2;
    }
  my_putstr("total ");
  my_put_nbr(total);
  my_putchar('\n');
  dir_p = opendir(".");
  while ((file_read = readdir(dir_p)) != NULL)
    {
      if (file_read->d_name[0] != '.')
	{
	  lstat(file_read->d_name, &file_info);
	  my_rights(&file_info, file_read->d_name, file_read, ".");
	  my_putchar('\n');
	}
    }
}

void	my_display_total(int total)
{
  my_putstr("total ");
  my_put_nbr(total);
  my_putchar('\n');
}

void	my_lslarg(DIR* dir_p, struct stat file_info,
		  struct dirent *file_read, char *my_dir)
{
  int	total;
  char	*pathname;

  total = 0;
  while ((file_read = readdir(dir_p)) != NULL)
    {
      pathname = my_pathname(file_read, my_dir);
      lstat(pathname, &file_info);
      if (file_read->d_name[0] != '.')
	total += file_info.st_blocks / 2;
      free(pathname);
    }
  my_display_total(total);
  dir_p = opendir(my_dir);
  while ((file_read = readdir(dir_p)) != NULL)
    {
      pathname = my_pathname(file_read, my_dir);
      lstat(pathname, &file_info);
      if (file_read->d_name[0] != '.')
	{
	  my_rights(&file_info, file_read->d_name, file_read, my_dir);
	  my_putchar('\n');
	}
      free(pathname);
    }
}

void	my_ls_display(int a, DIR* dir_p, char *my_dir, char *str)
{
  struct stat	file_info;
  struct dirent	*file_read;

  file_read = NULL;
  lstat(my_dir, &file_info);
  if (a == 0)
    my_lslarg(dir_p, file_info, file_read, my_dir);
  else
    {
      file_read = readdir(dir_p);
      lstat(str, &file_info);
      my_rights(&file_info, str, file_read, my_dir);
      my_putchar('\n');
    }
}

void	my_which(char *str)
{
  int	a;
  int	b;
  char *my_name;
  char *my_dir;
  DIR* dir_p;

  a = my_strlen(str) - 1;
  b = 0;
  my_name = malloc(a * sizeof(char));
  my_dir = malloc(a * sizeof(char));
  my_name = my_display_condition(str, my_name, a, b);
  my_dir = my_display_previous(str, my_dir, a, b);
  dir_p = opendir(str);
  if (dir_p == NULL)
    {
      my_name = malloc(a * sizeof(char));
      my_name = my_display_condition2(str, my_name, a, b);
      a = 1;
    }
  else if (dir_p != NULL)
    {
      my_name = malloc(a * sizeof(char));
      my_dir = malloc(a * sizeof(char));
      my_dir = my_display_previous2(str, my_dir, a, b);
      my_strcat(my_dir, my_name);
      if (my_dir[my_strlen(my_dir) - 1] != '/')
	my_strcat(my_dir, "/\0");
      a = 0;
    }
  free(my_name);
  dir_p = opendir(my_dir);
  my_ls_display(a, dir_p, my_dir, str);
  free(my_dir);
  free(my_name);
}

void	my_which2()
{
  DIR* dir_p;
  struct stat	file_info;
  struct dirent	*file_read;

  file_read = NULL;
  dir_p = opendir(".");
  file_read = readdir(dir_p);
  my_lsl(dir_p, file_info, file_read);
}

void	my_ls(char *str)
{
  DIR* dir_p;
  struct dirent	*file_read;

  dir_p = opendir(str);
  while ((file_read = readdir(dir_p)) != NULL)
    {
      if (file_read->d_name[0] != '.')
	{
	  my_putstr(file_read->d_name);
	  my_putchar(' ');
	}
    }
  my_putchar('\n');
}

void	my_lsr(char *str)
{
  DIR* dir_p;
  struct dirent	*file_read;
  char	**tab;
  int	a;

  a = 0;
  dir_p = opendir(str);
  tab = malloc(sizeof(char*) * 500);
  while ((file_read = readdir(dir_p)) != NULL)
    {
      if (file_read->d_name[0] != '.')
	tab[a++] = file_read->d_name;
    }
  a--;
  while (a >= 0)
    {
      my_putstr(tab[a--]);
      my_putchar(' ');
    }
  my_putchar('\n');
}

void	my_lsR(char *str)
{
  DIR* dir_p;
  struct stat	file_info;
  struct dirent	*file_read;
  char	**tab;
  int	a;

  a = 0;
  dir_p = opendir(str);
  tab = malloc(sizeof(char*) * 500);
  my_putstr(".:");
  my_printf("%s\n", str);
  my_ls(str);
  while ((file_read = readdir(dir_p)) != NULL)
    {
      lstat(str, &file_info);
      if (file_read->d_name[0] != '.')
	tab[a++] = file_read->d_name;
    }
  a = 0;
  while (tab[a] != NULL)
    {
      my_putstr(tab[a--]);
      my_putchar(' ');
    }
  my_putchar('\n');
}

void	my_lsa(char *str)
{
  DIR* dir_p;
  struct dirent	*file_read;

  dir_p = opendir(str);
  while ((file_read = readdir(dir_p)) != NULL)
    {
      my_putstr(file_read->d_name);
      my_putchar(' ');
    }
  my_putchar('\n');
}

void	my_execute(char *str, char *str2, int argc)
{
  if (str[1] == 'l' && argc >= 2)
    my_which(str2);
  else if (str[1] == 'l')
    my_which2();
  else if (str[1] == 'r' && argc >= 2)
    my_lsr(str2);
  else if (str[1] == 'r')
    my_lsr(".");
  else if (str[1] == 'd' && argc >= 2)
    my_printf("%s\n", str2);
  else if (str[1] == 'd')
    my_putstr(".\n");
  else if (str[1] == 'R' && argc >= 2)
    my_lsR(str2);
  else if (str[1] == 'R')
    my_putstr(".\n");
  else if (str[1] == 'a' && argc >= 2)
    my_lsa(str2);
  else if (str[1] == 'a')
    my_lsa(".");
}

int	main(int argc, char **argv)
{
  int	a;

  a = 1;
  while (a != argc && argv[a][0] != '-')
    a++;
  if (argc == 1)
    my_ls(".");
  else if (a == (argc - 1))
    {
      if (argv[a][0] == '-' && (argv[a - 1] != argv[0]))
	my_execute(argv[a], argv[a - 1], argc);
      else
	my_execute(argv[a], ".", argc);
    }
  else if (argv[1][0] != '-')
    my_ls(argv[1]);
  else
    {
      if (argc >= 2)
	my_execute(argv[a], argv[a + 1], argc);
    }
  return (0);
}

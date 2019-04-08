/*
** mar_if_path_name.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Wed May 17 11:33:41 2017 Marius
** Last update Thu May 18 18:22:32 2017 Marius
*/

#include "42sh.h"

char    *if_path(char *str)
{
  char  *path;
  int   i;

  path = malloc(sizeof(char) * (strlen(str) + 1));
  if (no_slash(str) == 1)
    {
      path[0] = '.';
      path[1] = '\0';
    }
  else
    {
      i = -1;
      while (str[++i] != '\0')
	path[i] = str[i];
      path[i] = '\0';
      while (i != 0 && path[i] != '/')
	path[i--] = '\0';
      path[i] = '\0';
    }
  return (path);
}

char    *if_name(char *str)
{
  int   i;
  char  *name;
  int   a;

  a = 0;
  i = strlen(str);
  name = malloc(sizeof(char) * (strlen(str) + 1));
  while (i != 0 && str[i] != '/')
    i--;
  while (str[i] != '\0')
    name[a++] = str[i++];
  name[a] = '\0';
  return (name);
}

int     int_star(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*')
	return (1);
      i++;
    }
  return (0);
}

int	int_inter(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '?')
	return (1);
      i++;
    }
  return (0);
}

int     no_slash(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (0);
      i++;
    }
  return (1);
}

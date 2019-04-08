/*
** get_path.c for 42 in /home/hugo/Projet/Sysunix/PSU_2016_42sh/hugo
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Wed Apr 26 11:10:56 2017 Hugo
** Last update Sat May 20 11:38:57 2017 Régis Berthelot
*/

#include "42sh.h"

char	*get_path(char *env, char *cmd)
{
  int	i;
  int	nb;
  char	*file;

  i = 0;
  nb = comptnb(env);
  if (access(cmd, F_OK) == 0)
    return (cmd);
  while (i <= nb)
    {
      file = get_line(env, i);
      if (access(assemblage(file, cmd), F_OK) == 0)
	return (file);
      free(file);
      i++;
    }
  printf("%s: Command not found.\n", cmd);
  g_return_value = 1;
  return (NULL);
}

char    *getvarenv(char **env, char *what, int i)
{
  int   y;
  int   e;
  char  *str;

  y = 0;
    e = 0;
  while (what[e] != '\0' && env[y] != NULL)
    {
      if (env[y][i] != what[e])
	{
	  e = -1;
	  y++;
	  i = -1;
	}
      e++;
      i++;
    }
  if (env[y] == NULL)
    return (NULL);
  str = malloc(sizeof(char) * (strlen(env[y] + 1)));
  str = my_strcpi(env[y]);
  return (str);
}

int     comptnb(char *path)
{
  int   nb;
  int   i;

  i = 0;
  nb = 0;
  while (path[i] != '\0')
    {
      if (path[i] == ':')
	nb++;
      i++;
    }
  return (nb);
}

char    *assemblage(char *debut, char *fin)
{
  int   i;
  int   y;

  i = 0;
  y = 0;
  while (debut[i] != '\0')
    i++;
  debut[i] = '/';
  i++;
  while (fin[y] != '\0')
    {
      debut[i] = fin[y];
      i++;
      y++;
    }
  debut[i] = '\0';
  return (debut);
}

char    *get_line(char *path, int nb)
{
  int   i;
  int   y;
  char  *str;

  str = malloc(sizeof(char) * (170));
  y = 0;
  i = 5;
  while (y != nb)
    {
      while (path[i] != ':')
	i++;
      y++;
      i++;
    }
  y = 0;
  while (path[i] != ':' && path[i] != '\0')
    {
      str[y] = path[i];
      i++;
      y++;
    }
  str[y] = '\0';
  return (str);
}

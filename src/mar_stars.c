/*
** mar_stars.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Wed May 17 11:29:12 2017 Marius
** Last update Sat May 20 18:41:43 2017 Marius
*/

#include "42sh.h"

char    **if_good(char **tab, char *name)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (star_start(tab[i], name) == 0 ||
	  star_end(tab[i], name) == 0)
	{
	  while (tab[i + 1] != NULL)
	    {
	      swap_str(&tab[i], &tab[i + 1]);
	      i++;
	    }
	  tab[i] = NULL;
	  i = -1;
	}
      i++;
    }
  return (tab);
}

char	**put_path(char *path, char **tab)
{
  int	i;
  int	a;
  int	x;
  char	**res;

  i = 0;
  if (path[1] == '\0')
    return (tab);
  res = malloc(sizeof(char *) * (tablen(tab) + 1));
  while (tab[i] != NULL)
    {
      x = 0;
      a = 0;
      res[i] = malloc(sizeof(char) * (strlen(tab[i]) + strlen(path) + 2));
      while ((path[x] != '\0') && (res[i][a++] = path[x++]));
      res[i][a++] = '/';
      x = 0;
      while ((tab[i][x] != '\0') && (res[i][a++] = tab[i][x++]));
      res[i++][a] = '\0';
    }
  res[i] = NULL;
  free(tab);
  return (res);
}

char	**assemble_tab(char **tab, char **tab_fich, int i)
{
  char	**res;
  int	x;
  int	a;

  x = 0;
  a = 0;
  res = malloc(sizeof(char *) * (tablen(tab) + tablen(tab_fich) + 1));
  while (x != i)
    {
      res[x] = tab[x];
      x++;
    }
  while (tab_fich[a] != NULL)
    res[x++] = tab_fich[a++];
  i++;
  while (tab[i] != NULL)
    res[x++] = tab[i++];
  res[x] = NULL;
  return (res);
}

char    **change_star(char **tab, int i)
{
  char  *path;
  char  *name;
  char  **tab_fich;

  path = if_path(tab[i]);
  name = if_name(tab[i]);
  if ((tab_fich = read_dir(path)) == NULL)
    return (tab);
  tab_fich = if_good(tab_fich, name);
  if (tab_fich[0] == NULL)
    {
      tab = put_no_match(tab, i);
      return (tab);
    }
  else
    {
      tab_fich = put_path(path, tab_fich);
      tab = assemble_tab(tab, tab_fich, i);
    }
  return (tab);
}

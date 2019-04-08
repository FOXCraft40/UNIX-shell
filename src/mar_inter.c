/*
** mar_iner.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Thu May 18 15:47:07 2017 Marius
** Last update Thu May 18 16:06:51 2017 Fernand Matignon
*/

#include "42sh.h"

int     good2(char *str, char *name)
{
  int   i;
  int   x;

  i = 0;
  if (name[0] == '/')
    x = 1;
  else
    x = 0;
  while (str[i] != '\0')
    {
      if (str[i] != name[x] && name[i] != '?')
	return (0);
      x++;
      i++;
    }
  return (str[i] == '\0' && name[x] == '\0');
}

char    **if_good2(char **tab, char *name)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (good2(tab[i], name) == 0)
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

char	**change_inter(char **tab, int i)
{
  char  *path;
  char  *name;
  char  **tab_fich;

  path = if_path(tab[i]);
  name = if_name(tab[i]);
  tab_fich = read_dir(path);
  tab_fich = if_good2(tab_fich, name);
  tab_fich = put_path(path, tab_fich);
  my_put_tab(tab_fich);
  tab = assemble_tab(tab, tab_fich, i);
  return (tab);
}

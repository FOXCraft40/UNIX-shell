/*
** put_alias.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Fri May 19 19:38:28 2017 Marius
** Last update Sat May 20 18:28:02 2017 Marius
*/

#include "42sh.h"

char	*decoup_alias(char *str)
{
  int   a;
  char  *buf;

  if ((a = find_alias(str)) != -1)
    {
      buf = strdup(g_alias[a]);
      while (*buf++ != '=');
    }
  return (buf);
}

char	**compar_alias()
{
  int	i;
  char	**tab;

  tab = malloc(sizeof(char *) * tablen(g_alias));
  while (g_alias[i] != NULL)
    {
      tab[i] = strdup(g_alias[i]);
      tab[i] = decoup_alias(tab[i]);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

char	*put_alias2(char *str)
{
  char	**tab;
  int	i;
  int	x;
  char	**cut_alias;

  i = 0;
  tab = my_sep_to_char(str, ' ');
  cut_alias = compar_alias();
  while (tab[i] != NULL)
    {
      x = 0;
      while (cut_alias[x] != NULL)
	{
	  if (strcmp(cut_alias[x], tab[i]) == 0)
	    tab[i] = cut_alias[x];
	  x++;
	}
      i++;
    }
  str = put_in_str(tab);
  return (str);
}

char	**put_alias(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      tab[i] = put_alias2(tab[i]);
      i++;
    }
  return (tab);
}

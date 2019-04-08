/*
** mar_globing.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Sun May 14 17:56:57 2017 Marius
** Last update Sat May 20 17:34:12 2017 Marius
*/

#include "42sh.h"

char	*put_in_str(char **tab)
{
  char	*res;
  int	i;
  int	x;
  int	a;

  i = 0;
  a = 0;
  res = malloc(sizeof(char) * (size_malloc(tab) + 100));
  while (tab[i] != NULL)
    {
      x = 0;
      while (tab[i][x] != '\0')
	res[a++] = tab[i][x++];
      res[a++] = ' ';
      i++;
    }
  res[a] = '\0';
  return (res);
}

char	*star(char *str)
{
  char	**tab;
  int	i;

  tab = my_sep_to_char(str, ' ');
  i = 0;
  while (tab[i] != NULL)
    {
      if (int_star(tab[i]) == 1 || int_inter(tab[i]))
	tab = change_star(tab, i);
      if (tab == NULL)
	return (str);
      i++;
    }
  str = put_in_str(tab);
  return (str);
}

char	*globing(char *str)
{
  int	i;
  char	skip;

  i = 0;
  skip = '0';
  while (str[i] != '\0')
    {
      if ((str[i] == '\'') || (str[i] == '\"'))
	{
	  if (skip == '0')
	    skip = '1';
	  else
	    skip = '0';
	}
      if (skip == '0' && (str[i] == '*' || str[i] == '?'))
	return (str = star(str));
      i++;
    }
  return (str);
}

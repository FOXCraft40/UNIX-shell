/*
** alias.c for 42sh in /home/marius/epitech/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Fri Apr 28 15:37:04 2017 Marius
** Last update Sat May 20 18:15:50 2017 Marius
*/

#include "42sh.h"

void	realloc_alias(char *str)
{
  int	i;
  char	**tab;

  i = 0;
  tab = malloc(sizeof(char *) * (tablen(g_alias) + 2));
  while (g_alias[i] != NULL)
    {
      tab[i] = g_alias[i];
      i++;
    }
  tab[i++] = str;
  tab[i] = NULL;
  g_alias = malloc(sizeof(char *) * (tablen(tab) + 1));
  i = 0;
  while (tab[i] != NULL)
    {
      g_alias[i] = tab[i];
      i++;
    }
  g_alias[i] = NULL;
  free(tab);
}

int	size_malloc(char **tab)
{
  int	i;
  int	res;

  i = 1;
  res = 0;
  while (tab[i] != NULL)
    res += strlen(tab[i++]);
  return (res + tablen(tab));
}

/*
** alias.c for 42sh in /home/marius/epitech/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Fri Apr 28 15:37:04 2017 Marius
** Last update Sun May 21 11:26:46 2017 Régis Berthelot
*/

#include <fcntl.h>
#include "42sh.h"

int	find_alias(char *str)
{
  int	i;
  int	a;

  i = 0;
  while (g_alias[i] != NULL)
    {
      a = 0;
      while (g_alias[i][a] == str[a])
	a++;
      if (g_alias[i][a] == '\t' && str[a] == '\0')
	return (i);
      i++;
    }
  return (-1);
}

void	swap_str(char **str1, char **str2)
{
  char	*s;

  s = *str1;
  *str1 = *str2;
  *str2 = s;
}

int	mar_unalias(char **tab)
{
  int	i;
  int	a;

  i = 1;
  while (tab[i] != NULL)
    {
      if ((a = find_alias(tab[i])) != -1)
	{
	  a++;
	  while (g_alias[a] != NULL)
	    {
	      swap_str(&g_alias[a - 1], &g_alias[a]);
	      a++;
	    }
	  g_alias[--a] = NULL;
	}
      i++;
    }
  return (0);
}

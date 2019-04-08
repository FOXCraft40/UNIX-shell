/*
** no_match.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Sat May 20 15:45:06 2017 Marius
** Last update Sun May 21 11:26:33 2017 Régis Berthelot
*/

#include "42sh.h"

int	no_match(char **tab)
{
  printf("%s: No match.\n", tab[1]);
  return (1);
}

char	**put_no_match(char **tab, int	i)
{
  char	*res;

  if (i == 0)
    {
      res = malloc(sizeof(char) * (strlen("no_match ") + strlen(tab[i]) + 1));
      res = strcpy(res, "no_match ");
      res = strcat(res, tab[i]);
      tab[i] = res;
    }
  else
    {
      res = malloc(sizeof(char) * (strlen("no_match ")
				   + strlen(tab[i - 1]) + 1));
      res = strcpy(res, "no_match ");
      res = strcat(res, tab[i - 1]);
      tab[i - 1] = res;
      while (tab[i + 1] != NULL)
	{
	  swap_str(&tab[i], &tab[i + 1]);
	  i++;
	}
      tab[i] = NULL;
    }
  return (tab);
}

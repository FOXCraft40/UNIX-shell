/*
** mar_my_sep_to_char.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Wed May 17 11:32:35 2017 Marius
** Last update Sat May 20 09:09:28 2017 Régis Berthelot
*/

#include "42sh.h"

int     nb_of_return(char *str)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	x++;
      i++;
    }
  return (x);
}

int     my_mal(char *str, int i)
{
  int   a;

  a = 0;
  while (str[i] != '\n' && str[i++] != '\0')
    a++;
  return (a);
}

char    **my_sep_to_char(char *str, char c)
{
  int   i;
  int   a;
  int   x;
  char  **tab;

  tab = malloc(sizeof(char *) * (nb_of_return(str) + 2));
  i = (a = 0);
  while (str[i] != '\0')
    {
      x = 0;
      tab[a] = malloc(sizeof(char) * (my_mal(str, i) + 1));
      if (str[i] == '\'' || str[i] == '\"')
	{
	  tab[a] = malloc(sizeof(char) * (strlen(str) + 1));
	  tab[a][x++] = str[i++];
	  while ((str[i] != '\"' && str[i] != '\'') && (tab[a][x++] = str[i++]));
	  tab[a][x++] = str[i++];
	}
      else
	while ((str[i] != c && str[i] != '\0') && (tab[a][x++] = str[i++]));
      tab[a++][x] = '\0';
      (str[i] == '\0') ? i = i : i++;
    }
  tab[a] = NULL;
  return (tab);
}

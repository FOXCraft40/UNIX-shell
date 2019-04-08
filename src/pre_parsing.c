/*
** pre_parsing.c for pre_parsing in /home/spyros_kypriadis/PSU_2016_42sh/spyros
**
** Made by spyros_kypriadis
** Login   <spyros_kypriadis@epitech.net>
**
** Started on  Thu May 11 18:48:23 2017 spyros_kypriadis
** Last update Sun May 21 14:07:00 2017 Régis Berthelot
*/

#include "42sh.h"

char	**my_tab_realloc(char **tab)
{
  char	**res;
  int	i;
  int	n;

  i = 0;
  n = tablen(tab);
  if ((res = malloc(sizeof(char *) * (n + 2))) == NULL)
    exit(84);
  while (tab[i] != NULL)
    {
      res[i] = strdup(tab[i]);
      i++;
    }
  res[i + 1] = NULL;
  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  return (res);
}

char	*my_strcpy_xy(char *str, int x, int y)
{
  int	i;
  char	*res;

  i = 0;
  if ((res = malloc(sizeof(char) * (y + 1))) == NULL)
    exit(84);
  while (str[x] != '\0' && i < y)
    {
      res[i] = str[x];
      i++;
      x++;
    }
  res[i] = '\0';
  return (res);
}

int	number_of_cases(char *str, int n)
{
  int	i;

  i = 1;
  while (str[n] != '\0')
    {
      if (str[n] == ';')
	return (i);
      else if (str[n] == '|' && str[n + 1] == '|')
	return (i);
      else if (str[n] == '&' && str[n + 1] == '&')
	return (i);
      i++;
      n++;
    }
  return (i);
}

char	*fill(char *str, int i, int cases)
{
  char	*res;

  if (str[i] == ';')
    res = my_strcpy_xy(str, i, cases);
  else if ((str[i] == '|' && str[i + 1] == '|') ||
	   (str[i] == '&' && str[i + 1] == '&'))
    res = my_strcpy_xy(str, i + 1, cases - 1);
  return (res);
}

char	**pre_parsing(char *str)
{
  char	**tab;
  int	cases;
  int	i;
  int	n;
  int	y;

  i = 0;
  n = 0;
  y = strlen(str);
  if ((tab = calloc(2, sizeof(char *))) == NULL)
    exit(84);
  while (i < y)
    {
      cases = number_of_cases(str, i);
      if (i == 0)
	tab[n] = my_strcpy_xy(str, i, cases - 1);
      else
      	tab[n] = fill(str, i - 1, cases);
      i += cases;
      n++;
      if (i < (int)strlen(str))
	tab = my_tab_realloc(tab);
    }
  tab[n] = NULL;
  return (tab);
}

/*
** alias.c for 42sh in /home/marius/epitech/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Fri Apr 28 15:37:04 2017 Marius
** Last update Sun May 21 11:26:05 2017 Régis Berthelot
*/

#include "42sh.h"

char	*copy_(char **tab)
{
  char	*res;
  int	i;
  int	x;
  int	a;

  i = 1;
  a = 0;
  res = malloc(sizeof(char) * (size_malloc(tab) + 2));
  while (tab[i] != NULL)
    {
      x = 0;
      if (i == 2)
	res[a++] = '\t';
      else if (i != 1)
	res[a++] = ' ';
      while (tab[i][x] != '\0')
	{
	  res[a] = tab[i][x++];
	  a++;
	}
      i++;
    }
  res[a] = '\0';
  return (res);
}

int	compar_(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && str2[i] != '\0' && str2[i] != '\t')
    i++;
  if (str1[i] == '\0' && str2[i] == '\t')
    return (0);
  return (-1);
}

void	my_putalias(char *str)
{
  int	a;
  char	*buf;

  if ((a = find_alias(str)) != -1)
    {
      buf = strdup(g_alias[a]);
      while (*buf++ != '\t');
      printf("%s\n", buf);
    }
  return;
}

void	modif_alias(char **tab, int a)
{
  int	i;
  char	*buf;
  int	f;

  i = 0;
  while (g_alias[a][i++] != '\t');
  g_alias[a][i] = '\0';
  buf = strdup(g_alias[a]);
  i = 0;
  g_alias[a] = malloc(sizeof(char) * (size_malloc(tab) + 2));
  while (buf[i] != '\0')
    {
      g_alias[a][i] = buf[i];
      i++;
    }
  g_alias[a][i] = '\0';
  i = 2;
  while (tab[i] != NULL)
    {
      g_alias[a] = strcat(g_alias[a], tab[i++]);
      f = strlen(g_alias[a]);
      g_alias[a][f++] = '\t';
      g_alias[a][f] = '\0';
    }
}

int	mar_alias(char **tab)
{
  int	a;

  if (tablen(tab) == 1)
    my_put_tab(g_alias);
  else if (tablen(tab) == 2)
    my_putalias(tab[1]);
  else
    {
      if ((a = find_alias(tab[1])) == -1)
	realloc_alias(copy_(tab));
      else
	modif_alias(tab, a);
    }
  return (0);
}

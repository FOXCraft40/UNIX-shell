/*
** mar_stars2.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Fri May 19 17:30:48 2017 Marius
** Last update Fri May 19 17:33:41 2017 Marius
*/

#include "42sh.h"

int     star_end(char *str, char *name)
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
      if (str[i] != name[x] && name[x] != '?' && name[x] != '*')
	return (0);
      if (name[x] == '*')
	return (1);
      if (name[x] != '*' && name[x] != '\0')
	x++;
      i++;
    }
  return (1);
}

int     star_start(char *str, char *name)
{
  int   i;
  int   x;

  i = strlen(str);
  x = strlen(name);
  while (i != 0)
    {
      if (name[x] != '*' && x != 0)
	x--;
      i--;
      if (str[i] != name[x] && name[x] != '?' && name[x] != '*')
	return (0);
      if (name[x] == '*')
	return (1);
    }
  return (1);
}

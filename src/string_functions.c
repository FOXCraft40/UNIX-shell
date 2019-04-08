/*
** string_functions.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Tue Apr 25 09:12:44 2017 Régis Berthelot
** Last update Sun May 21 17:56:23 2017 Fernand Matignon
*/

#include "42sh.h"

void	copy_from(char *dest, char *src, int from)
{
  int	i;

  i = 0;
  while (src[from] != '\0')
    {
      dest[i] = src[from];
      ++i;
      ++from;
    }
  dest[i] = '\0';
}

void	copy_ft(char *dest, char *src, int from, int to)
{
  int	i;
  int	j;

  i = 0;
  j = from;
  while (i != (to - from))
    {
      dest[i] = src[j];
      ++i;
      ++j;
    }
  dest[i] = '\0';
}

char	*var_extract(char *str, int i)
{
  int	j;
  char	*varname;

  j = i;
  while (str[j] != ' ' && str[j] != '$' && str[j] != '\0'
	 && !(str[j] >= 35 && str[j] <= 47)
	 && !(str[j] >= 58 && str[j] <= 64))
    ++j;
  varname = malloc(j - i + 1);
  copy_ft(varname, str, i, j);
  return (varname);
}

void	chomp(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	str[i] = '\0';
      ++i;
    }
}

void	cat_from(char *dest, char *src, int from)
{
  int	i;

  i = 0;
  while (from > 1 && dest[from] != ' ')
    --from;
  if (dest[from] == ' ')
    ++from;
  else
    from = 0;
  while (src[i] != '\0')
    dest[from++] = src[i++];
  dest[from] = '\0';
}

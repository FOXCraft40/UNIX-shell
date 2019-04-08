/*
** tab_functions.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Mon Apr 24 10:34:24 2017 Régis Berthelot
** Last update Fri May 12 06:16:42 2017 Fernand Matignon
*/

#include "42sh.h"

extern char	**environ;

int	tab_length(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

void	tab_display(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", environ[i]);
      ++i;
    }
}

char	*env_extract(char *varname)
{
  int	i;
  char	*content;

  i = 0;
  while (environ[i] != NULL)
    {
      if (strncmp(environ[i], varname, strlen(varname)) == 0)
	break ;
      ++i;
    }
  if (environ[i] == NULL)
    return (NULL);
  content = malloc(strlen(environ[i]) - strlen(varname));
  copy_from(content, environ[i], strlen(varname) + 1);
  return (content);
}

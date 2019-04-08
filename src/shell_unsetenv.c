/*
** unsetenv.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Mon Apr 24 10:41:31 2017 Régis Berthelot
** Last update Thu May 18 03:30:40 2017 Fernand Matignon
*/

#include "42sh.h"

int	shell_unsetenv(char **args_tab)
{
  int	i;

  if (!args_tab[1])
    {
      dprintf(2, "unsetenv: Too few arguments.\n");
      return (1);
    }
  i = 1;
  while (args_tab[i] != NULL)
    {
      unsetenv(args_tab[i]);
      ++i;
    }
  return (0);
}

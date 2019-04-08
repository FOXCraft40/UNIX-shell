/*
** echo.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu May 11 15:51:47 2017 Régis Berthelot
** Last update Sun May 21 11:34:35 2017 Régis Berthelot
*/

#include "42sh.h"

static void	muh_putstring(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '"')
	write(1, &str[i], 1);
      ++i;
    }
}

int	shell_echo(char **args_tab)
{
  int	i;
  int	noline;

  if (args_tab[1] == NULL)
    {
      printf("\n");
      return (0);
    }
  i = 1;
  noline = strcmp(args_tab[1], "-n");
  if (noline == 0)
    i = 2;
  while (args_tab[i] != NULL)
    {
      muh_putstring(args_tab[i]);
      if (args_tab[i++ + 1] != NULL)
	printf(" ");
    }
  if (noline != 0)
    printf("\n");
  return (0);
}

/*
** shell_setenv.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Mon Apr 24 09:09:01 2017 Régis Berthelot
** Last update Sun May 21 11:24:15 2017 Régis Berthelot
*/

#include "42sh.h"

int	shell_env(char **args_tab)
{
  int	length;

  length = tab_length(args_tab);
  if (length <= 1)
    {
      tab_display(environ);
      return (0);
    }
  else
    dprintf(2, "env: '%s': No such file or directory\n", args_tab[1]);
  return (1);
}

static short	setenv_valid_varname(char *varname)
{
  int		i;

  if (!((varname[0] >= 'A' && varname[0] <= 'Z')
	|| (varname[0] >= 'a' && varname[0] <= 'z'))
      || (varname[0] == '='))
    {
      dprintf(2, "setenv: Variable name must begin with a letter.\n");
      return (0);
    }
  i = 1;
  while (varname[i] != '\0')
    {
      if (!((varname[i] >= 'A' && varname[i] <= 'Z')
  	    || (varname[i] >= 'a' && varname[i] <= 'z')
  	    || (varname[i] >= '0' && varname[i] <= '9')))
  	{
	  dprintf(2, "setenv: Variable name must contain "
		  "alphanumeric characters.\n");
  	  return (0);
  	}
      ++i;
    }
  return (1);
}

int	shell_setenv(char **args_tab)
{
  short	varname_status;
  short	length;

  length = tab_length(args_tab);
  if (length <= 1)
    tab_display(environ);
  else
    {
      varname_status = setenv_valid_varname(args_tab[1]);
      if (!varname_status)
	return (1);
      if (length == 2)
	setenv(args_tab[1], "", 1);
      else if (length == 3)
	setenv(args_tab[1], args_tab[2], 1);
      else
	{
	  dprintf(2, "setenv: Too many arguments.\n");
	  return (1);
	}
    }
  return (0);
}


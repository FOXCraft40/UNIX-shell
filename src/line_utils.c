/*
** line_utils.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Wed Apr 26 16:48:01 2017 Régis Berthelot
** Last update Sun May 21 14:34:01 2017 Régis Berthelot
*/

#include "42sh.h"

static void	home_length(int *total, int *i)
{
  char		*var;

  var = env_extract("HOME");
  if (var)
    {
      *total += strlen(var);
      free(var);
    }
  else
    *total += 1;
  *i += 1;
}

static void	var_length(char *str, int *total, int *i)
{
  char		*var;
  char		*sub_var;

  var = var_extract(str, *i + 1);
  sub_var = env_extract(var);
  if (!sub_var)
    {
      *i += 1;
      free(var);
      return ;
    }
  *i += strlen(var) + 1;
  *total += strlen(sub_var);
  free(var);
  free(sub_var);
}

int	total_length(char *str, int i, int total)
{
  while (str[i] != '\0')
    {
      if (str[i] == '~'
	  && ((i > 0 && str[i - 1] != '\\') || i == 0))
	{
	  home_length(&total, &i);
	  continue ;
	}
      else if (str[i] == '$'
	       && (str[i + 1] != ' ' && str[i + 1] != '\0'
		   && str[i + 1] != '$')
	       && ((i > 0 && str[i - 1] != '\\') || i == 0))
	{
	  var_length(str, &total, &i);
	  continue ;
	}
      ++total;
      ++i;
    }
  return (total);
}

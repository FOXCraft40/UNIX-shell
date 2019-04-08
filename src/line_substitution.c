/*
** line_substitution.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Tue Apr 25 11:02:39 2017 Régis Berthelot
** Last update Sun May 21 14:36:32 2017 Régis Berthelot
*/

#include "42sh.h"

static void	tilde_sub(char *str, char *full_line, int j)
{
  char		*var;

  if (str[j] == '~')
    {
      if (j == 0)
	{
	  var = env_extract("HOME");
	  strcat(full_line, var != NULL ? var : "~");
	  free(var);
	}
      else if (str[j - 1] != '\\')
	{
	  var = env_extract("HOME");
	  strcat(full_line, var != NULL ? var : "~");
	  free(var);
	}
    }
}

static int	var_sub(char *str, char *full_line, int *i, int *j)
{
  char		*var;
  char		*var_cnt;

  var = var_extract(str, *j + 1);
  var_cnt = env_extract(var);
  if (var_cnt == NULL)
    {
      *j += strlen(var) + 1;
      dprintf(2, "%s: Undefined variable.\n", var);
      free(var);
      return (0);
    }
  *j += strlen(var) + 1;
  *i += strlen(var_cnt);
  strcat(full_line, var_cnt);
  free(var);
  free(var_cnt);
  return (1);
}

static char	*inner_sub(char *str, char *full_line, int i, int j)
{
  while (str[j] != '\0')
    {
      if (str[j] == '\\')
	++j;
      if (str[j] == '~' && ((j > 0 && str[j - 1] != '\\') || j == 0))
	{
	  tilde_sub(str, full_line, j++);
	  i = strlen(full_line);
	  continue ;
	}
      else if (str[j] == '$' && ((j > 0 && str[j - 1] != '\\') || j == 0)
	       && (str[j + 1] != ' ' && str[j + 1] != '\0'))
	{
	  if (var_sub(str, full_line, &i, &j) == 0)
	    {
	      free(full_line);
	      return (NULL);
	    }
	  continue ;
	}
      full_line[i++] = str[j++];
    }
  return (full_line);
}

char	*line_substitution(char *str)
{
  char	*full_line;

  full_line = calloc(total_length(str, 0, 0) + 2, 1);
  full_line = inner_sub(str, full_line, 0, 0);
  return (full_line ? full_line : NULL);
}

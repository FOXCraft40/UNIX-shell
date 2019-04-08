/*
** shell_exit.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Tue Apr 25 09:23:29 2017 Régis Berthelot
** Last update Sat May 20 15:15:48 2017 Fernand Matignon
*/

#include "42sh.h"

static int	parentheses_error(int par)
{
  if (par > 0)
    dprintf(2, "Too many ('s.\n");
  else if (par < 0)
    dprintf(2, "Too many )'s.\n");
  return (-12);
}

static int	check_parentheses(int *prth, int *i, int *val, char *str)
{
  if (str[*i] == '(')
    {
      ++*prth;
      return (1);
    }
  if (str[*i] == ')')
    {
      --*prth;
      return (1);
    }
  if ((str[*i] >= '0' && str[*i] <= '9') && *val == -1)
    {
      *val = nbr_extract_from(str, i);
      return (1);
    }
  return (0);
}

static int	check_expr_syn(char *str, int nbrs[])
{
 if ((str[nbrs[0]] != '(' && str[nbrs[0]] != ')' && str[nbrs[0]] != '-') &&
	  ((nbrs[2] != -1 && str[nbrs[0]] >= '0' && str[nbrs[0]] <= '9')
	   || (nbrs[2] == -1 && !(str[nbrs[0]] >= '0' && str[nbrs[0]] <= '9'))))
   {
     dprintf(2, "exit: Expression Syntax.\n");
     return (-12);
   }
 return (0);
}

static int	get_exit_value(char *str)
{
  int		nbrs[4];

  nbrs[0] = 0;
  nbrs[1] = 1;
  nbrs[2] = -1;
  nbrs[3] = 0;
  while (str[nbrs[0]] != '\0')
    {
      if (str[nbrs[0]] == '-')
	nbrs[1] *= -1;
      if (check_parentheses(&nbrs[3], &nbrs[0], &nbrs[2], str) != 0);
      else if (check_expr_syn(str, nbrs) == -12)
	return (-12);
      else if ((str[nbrs[0]] != '(' && str[nbrs[0]] != ')'
		&& str[nbrs[0]] != '-') &&
	       (nbrs[2] != -1 && !(str[nbrs[0]] >= '0' && str[nbrs[0]] <= '9')))
	{
	  dprintf(2, "exit: Badly formed number.\n");
	  return (-12);
	}
      ++nbrs[0];
    }
  return (nbrs[3] != 0 ? parentheses_error(nbrs[3]) : nbrs[2] * nbrs[1]);
}

int	shell_exit(char **args_tab)
{
  int	value;

  value = 0;
  if (args_tab[2] && strlen(args_tab[2]) > 0)
    {
      dprintf(2, "exit: Expression syntax.\n");
      return (1);
    }
  else if (args_tab[1] != NULL)
    value = get_exit_value(args_tab[1]);
  if (value != -12)
    exit(value);
  else
    return (1);
}

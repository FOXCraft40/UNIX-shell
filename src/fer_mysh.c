/*
** fer_mysh.c for while mysh in /home/fox/epitech/PSU_2016_42sh/fernand
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Fri Apr 28 14:29:30 2017 Fernand Matignon
** Last update Sun May 21 15:34:13 2017 Fernand Matignon
*/

#include "42sh.h"

void	my_put_tab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    puts(tab[x++]);
}

void	my_freetab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    free(tab[x++]);
  free(tab);
}

void	mult_exe(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    {
      if ((tab[x][0] != '&') && (tab[x][0] != '|') && (tab[x][0] != ';'))
	exec(tab[x], &environ);
      if ((tab[x][0] == '&') && (tab[x][0] = ' ') && (g_return_value == 0))
	exec(tab[x], &environ);
      else if ((tab[x][0] == '|') && (tab[x][0] = ' ')
	       && (g_return_value != 0))
	exec(tab[x], &environ);
      else if ((tab[x][0] == ';') && (tab[x][0] = ' '))
	exec(tab[x], &environ);
      x++;
    }
}

int     fer_mysh()
{
  char  **tab;

  tab = NULL;
  while (1)
    {
      signal(SIGINT, fer_ctrl_c);
      tab = fer_prompt();
      if (tab != NULL)
	{
	  mult_exe(tab);
	  get_history(0, 1);
	  my_freetab(tab);
	}
    }
  return (1);
}

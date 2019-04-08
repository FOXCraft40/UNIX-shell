/*
** fer_prompt.c for prompt 42sh in /home/fox/epitech/PSU_2016_42sh/fernand
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Fri Apr 28 14:32:25 2017 Fernand Matignon
** Last update Sun May 21 14:06:37 2017 Régis Berthelot
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	**fer_line_form(char *str)
{
  char	**tab;

  tab = NULL;
  str = line_substitution(str);
  str = globing(str);
  tab = pre_parsing(str);
  free(str);
  return (tab);
}

char	**fer_prompt()
{
  char	*buffer;
  char	**tab;
  int	is_a_t;

  is_a_t = 0;
  tab = NULL;
  if ((isatty(0) != 0))
    {
      write(1, "42sh $ ", 7);
      is_a_t = 1;
    }
  buffer = NULL;
  if ((buffer = rdline()) == NULL)
    {
      if (is_a_t == 1)
        write(1, "exit\n", 5);
      exit(g_return_value);
    }
  else if (buffer[0] != '\0')
    {
      chomp(buffer);
      tab = fer_line_form(buffer);
      return (tab);
    }
  return (NULL);
}

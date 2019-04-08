/*
** main.c for  main quarentdeush in /home/fox/epitech/PSU_2016_42sh/fernand
**
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
**
** Started on  Fri Apr 28 14:29:44 2017 Fernand Matignon
** Last update Sun May 21 13:59:52 2017 Régis Berthelot
*/

#include "42sh.h"

int	main(void)
{
  g_return_value = 0;
  g_cmd_hist = malloc(sizeof(char *));
  g_cmd_hist[0] = NULL;
  g_alias = malloc(sizeof(char *));
  g_alias[0] = NULL;
  fer_mysh();
  my_freetab(g_cmd_hist);
  return (g_return_value);
}

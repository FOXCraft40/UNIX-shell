/*
** tablen.c for 42sh in /home/spyros_kypriadis/PSU_2016_42sh/spyros
**
** Made by spyros_kypriadis
** Login   <spyros_kypriadis@epitech.net>
**
** Started on  Thu May 11 19:57:55 2017 spyros_kypriadis
** Last update Sun May 21 14:05:09 2017 Régis Berthelot
*/

#include "42sh.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

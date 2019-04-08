/*
** fer_signal.c for signal 42sh in /home/fox/epitech/PSU_2016_42sh/fernand
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Fri Apr 28 14:57:34 2017 Fernand Matignon
** Last update Sun May 21 14:06:51 2017 Régis Berthelot
*/

#include "42sh.h"

void    fer_ctrl_c()
{
  write(1, "\n", 1);
}


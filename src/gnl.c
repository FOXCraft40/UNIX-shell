/*
** gnl.c for gnl in /home/hugo/Projet/CProg_elem/CPE_2016_matchstick
**
** Made by Hugo Perier
** Login   <hugo@epitech.net>
**
** Started on  Thu Feb 23 10:47:28 2017 Hugo Perier
** Last update Sun May 21 13:59:13 2017 Régis Berthelot
*/

#include "42sh.h"

char	*get_next_line(const int fd)
{
  char  *res;
  char  buf;
  int   red;

  red = read(fd, &buf, 1);
  if (red == 0 || red == -1)
    return (NULL);
  res = malloc(sizeof(char) * 1000);
  red = 0;
  res[red] = buf;
  red = red + 1;
  while (red < 1000 && buf != '\n')
    {
      read(fd, &buf, 1);
      res[red] = buf;
      red++;
    }
  if (red >= 1000)
    {
      dprintf(2, "Il y a eu des erreurs.\n");
      return (NULL);
    }
  res[red - 1] = '\0';
  return (res);
}

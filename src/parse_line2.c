/*
** parse_line2.c for parsing in /home/hugo/Projet/Sysunix/PSU_2016_42sh/hugo
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Wed Apr 26 10:00:57 2017 Hugo
** Last update Thu May 18 10:44:52 2017 Régis Berthelot
*/

#include "42sh.h"

char    **my_malloc(int hauteur, int largeur)
{
  int   i;
  char  **map;

  i = 0;
  map = malloc(sizeof(char *) * (hauteur + 2));
  while (i != hauteur + 1)
    {
      map[i] = calloc(largeur + 3, 1);
      i++;
    }
  map[i] = NULL;
  return (map);
}

void	my_aff_tab(char **tab)
{
  int	y;

  y = 0;
  while (tab[y])
    {
      printf(">%s<\n", tab[y]);
      y++;
    }
}

void	my_aff_struct(t_exe *cmd)
{
  int	i;

  i = 0;
  while (cmd[i].cmd[0][0] != '\0')
    {
      my_aff_tab(cmd[i].cmd);
      printf("et le next >%c<\n", cmd[i].next);
      i++;
    }
}

char    *my_strcpi(char *src)
{
  int   i;
  char  *str;

  i = 0;
  str = malloc(sizeof(char) * (strlen(src) + 1));
  while (src[i] != '\0')
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  src[i] = '\0';
  return (str);
}

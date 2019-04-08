/*
** mar_read_dir.c for 42sh in /home/marius/epitech/PSU_2016_minishell2/test
** 
** Made by Marius
** Login   <marius@epitech.net>
** 
** Started on  Wed May 17 11:25:15 2017 Marius
** Last update Sun May 21 14:01:27 2017 Régis Berthelot
*/

#include <dirent.h>
#include "42sh.h"

char    *my_cpy(char *src, char *dest)
{
  int   i;

  i = 0;
  dest = malloc(sizeof(char) * (strlen(src) + 1));
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int		lenth_of_dir(char *path)
{
  DIR		*fd;
  int		i;
  struct dirent	*dir;

  i = 0;
  if (!(fd = opendir(path)))
    return (0);
  while ((dir = readdir(fd)))
    {
      if (dir->d_name[0] != '.')
	{
	  i++;
	}
    }
  closedir(fd);
  return (i + 1);
}

char		**read_dir(char *path)
{
  DIR		*fd;
  char		**tab;
  int		i;
  struct dirent	*dir;

  i = 0;
  tab = malloc(sizeof(char *) * lenth_of_dir(path));
  if (!(fd = opendir(path)))
    return (NULL);
  while ((dir = readdir(fd)))
    {
      if (dir->d_name[0] != '.')
	{
	  tab[i] = my_cpy(dir->d_name, tab[i]);
	  i++;
	}
    }
  tab[i] = NULL;
  closedir(fd);
  return (tab);
}

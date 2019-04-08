/*
** fer_auto_comp.c for AUto completion 42sh  in /home/fox/epitech/PSU_2016_42sh/src
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Thu May 18 17:12:34 2017 Fernand Matignon
** Last update Sun May 21 17:18:15 2017 Fernand Matignon
*/

#include <42sh.h>

char	**last_word(char *line)
{
  int	l;
  int	i;
  char	**tab;

  i = 0;
  tab = malloc(sizeof(char *) * 2);
  l = strlen(line);
  tab[0] = malloc(sizeof(char) * (l + 2));
  while ((line[l] != ' ') && (l > 0))
    l--;
  if (line[l] == ' ')
    l++;
  while (line[l] != '\0')
    {
      tab[0][i] = line[l];
      l++;
      i++;
    }
  tab[0][i] = '\0';
  tab[1] = NULL;
  return (tab);
}

char	**add_star(char *line)
{
  int	l;
  int	i;
  char	**tab;

  tab = malloc(sizeof(char *) * 2);
  i = 0;
  l = strlen(line);
  tab[0] = malloc(sizeof(char) * (l + 2));
  while (line[i] != '\0')
    {
      tab[0][i] = line[i];
      i++;
    }
  tab[0][i++] = '*';
  tab[0][i] = '\0';
  tab[1] = NULL;
  return (tab);
}

void	put_auto_c(char **tab)
{
  int	x;

  x = 0;
  printf("\n");
  while (tab[x] != NULL)
    {
      printf("%s ", tab[x]);
      x++;
    }
  printf("\n");
}

char	*fer_auto_c(char *line)
{
  int	i;
  char	**tab;

  i = 0;
  tab = last_word(line);
  tab = add_star(tab[0]);
  tab = change_star(tab, i);
  if (tab_length(tab) > 1)
    {
      put_auto_c(tab);
      my_freetab(tab);
      return (NULL);
    }
  else if ((tab_length(tab) == 1) && (strncmp("no_match", tab[0], 7) != 0))
    return (tab[0]);
  else if (tab_length(tab) == 0)
    {
      my_freetab(tab);
      return (NULL);
    }
  my_freetab(tab);
  return (NULL);
}

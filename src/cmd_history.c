/*
** cmd_history.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Fri May 12 14:01:48 2017 Régis Berthelot
** Last update Sun May 21 17:35:17 2017 Fernand Matignon
*/

#include "42sh.h"

void	append_to_history(char *line)
{
  int	i;
  char	**newtab;

  if ((newtab = malloc(sizeof(char *) * (tablen(g_cmd_hist) + 2))) == NULL)
    exit(84);
  i = 0;
  while (g_cmd_hist[i] != NULL)
    {
      newtab[i] = strdup(g_cmd_hist[i]);
      ++i;
    }
  newtab[i] = malloc(strlen(line) + 1);
  strcpy(newtab[i], line);
  newtab[i + 1] = NULL;
    i = 0;
  while (g_cmd_hist[i] != NULL)
    free(g_cmd_hist[i++]);
  free(g_cmd_hist);
  g_cmd_hist = newtab;
}

void	rd_history(t_rdline *rdline, char *dir)
{
  char	*cmd_from_history;

  cmd_from_history = NULL;
  memset(rdline->line, '\0', 127);
  if ((strcmp(dir, "up") == 0))
    (cmd_from_history = get_history(1, 0));
  else if (strcmp(dir, "down") == 0)
    (cmd_from_history = get_history(-1, 0));
  if (cmd_from_history != NULL)
    {
      strcpy(rdline->line, cmd_from_history);
      rdline->count = (int)strlen(rdline->line);
      free(cmd_from_history);
    }
  else
    rdline->count = 0;
}

char		*get_history(int dir, short reset)
{
  static int	line = 0;
  int		i;

  if (reset == 1 || g_cmd_hist[0] == NULL)
    {
      line = 0;
      return (NULL);
    }
  i = 0;
  while (g_cmd_hist[i] != NULL)
    ++i;
  if (line == i  && dir == 1 && i != 0)
    return (strdup(g_cmd_hist[0]));
  else if (line == 0 && dir == -1)
    return (NULL);
  line += dir;
  i -= line;
  return (g_cmd_hist[i] != NULL && i >= 0 ? strdup(g_cmd_hist[i]) : NULL);
}


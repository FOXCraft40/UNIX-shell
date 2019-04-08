/*
** parse_line.c for parsing in /home/hugo/Projet/Sysunix/PSU_2016_42sh/hugo
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Wed Apr 26 09:55:29 2017 Hugo
** Last update Sun May 21 14:02:43 2017 Régis Berthelot
*/

#include "42sh.h"

int     str_to_cmd(char *line, t_exe **exe)
{
  t_var	v;
  int   err;

  v.o = 0;
  v.y = 0;
  v.a = 0;
  v.i = 0;
  if (line[0] == '\0')
    return (84);
  while (line[v.i] == ' ' || line[v.i] == '\t')
    v.i++;
  if (line[v.i] == '\0')
    return (84);
  *exe = mallocstruct(line, 0, 1, 1);
  err = rempstruct(line, exe, v);
  return (err);
}

int     rempstruct(char *line, t_exe **exe, t_var v)
{
  while (line[v.i] != '\0')
    {
      if (line[v.i] == '|' || line[v.i] == ';' || line[v.i] == '>'
	  || line[v.i] == '<' || (line[v.i] == '>' && line[v.i + 1] == '>')
	  || (line[v.i] == '<' && line[v.i + 1] == '<'))
	{
	  if ((rempstruct2(exe, &v, line) == 84))
	    return (84);
	}
      else if (line[v.i] == ' ' || line[v.i] == '\t')
	rempstruct3(exe, &v, line);
      else
	{
	  (*exe)[v.a].cmd[v.y][v.o] = line[v.i];
	  v.i++;
	  v.o++;
	}
    }
  if (((*exe)[v.a].cmd[v.y] != NULL) &&
      (*exe)[v.a].cmd[v.y][0] == '\0' && ((*exe)[v.a].cmd[v.y] = NULL));
  else
    (*exe)[v.a].cmd[v.y + 1] = NULL;
  (*exe)[v.a + 1].next = '\0';
  return (0);
}

void    rempstruct3(t_exe **exe, t_var *v, char *line)
{
  while (line[v->i] == ' ' || line[v->i] == '\t')
    v->i++;
  if ((*exe)[v->a].cmd[v->y][0] != '\0')
    {
      (*exe)[v->a].cmd[v->y][v->o] = '\0';
      v->y++;
      v->o = 0;
    }
}

int     rempstruct2(t_exe **exe, t_var *v, char *line)
{
  if ((*exe)[v->a].cmd[0][0] == '\0')
    return (84);
  if ((line[v->i] == '>' && line[v->i + 1] == '>') ||
      (line[v->i] == '<' && line[v->i + 1] == '<'))
    {
      (*exe)[v->a].next = line[v->i] + 1;
      v->i++;
    }
  else
    (*exe)[v->a].next = line[v->i];
  if (v->o == 0)
    (*exe)[v->a].cmd[v->y] = NULL;
  else
    {
      (*exe)[v->a].cmd[v->y][v->o] = '\0';
      (*exe)[v->a].cmd[(v->y) + 1] = NULL;
    }
  if (line[(v->i) + 1] != '\0')
    {
      v->a++;
      v->o = 0;
      v->y = 0;
    }
  v->i++;
  return (0);
}

t_exe   *mallocstruct(char *l, int i, int buf, int max)
{
  t_exe	*exe;
  int   nbs;

  nbs = 1;
  while (l[i])
    {
      if (l[i] == ';' || l[i] == '|' || l[i] == '<' || l[i] == '>')
	{
	  nbs++;
	  if (buf > max)
	    max = buf;
	  buf = 0;
	}
      buf++;
      i++;
    }
  max = buf;
  exe = malloc(sizeof(t_exe) * (nbs + 2));
  i = 0;
  while (i <= nbs + 1)
    {
      exe[i].cmd = my_malloc(max, max);
      exe[i++].next = '\0';
    }
  return (exe);
}

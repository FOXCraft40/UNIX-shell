/*
** execute2.c for execute2 in /home/hugo/Projet/Sysunix/PSU_2016_42sh_mission/src
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Fri May 19 17:49:38 2017 Hugo
** Last update Sun May 21 10:54:02 2017 Hugo
*/

#include "42sh.h"

void	exec_scd(t_exe **exe, t_f *b, int (*p)[2], char ***env)
{
  if (((*exe)[b->i].next == '<' && b->pid == 0))
    exec_chevg(*exe, *b, *env);
  else if (((*exe)[b->i].next == '>' ||
	    (*exe)[b->i].next == '?') && b->pid == 0)
    {
      exec_chevd(*exe, *b, *env);
      b->i += 1;
    }
  else if ((*exe)[b->i].next == '=')
    {
      if (b->pid == 0)
	exec_chevgg(*exe, *b, *p, *env);
      wait(NULL);
      b->i++;
      if ((*exe)[b->i].next == '\0')
	b->bool = 1;
    }
  else if (((*exe)[b->i].next == '|' || (b->bool == 1
	  && (*exe)[b->i-1].next == '|')) && b->pid == 0)
    exec_pipe(*exe, *b, *p, *env);
  else
    {
      close((*p)[1]);
      b->old_fd = (*p)[0];
    }
}

int     is_builtin(char **cmd)
{
  if (strcmp(cmd[0], "cd") == 0)
    return (shell_cd(cmd));
  if (strcmp(cmd[0], "echo") == 0)
    return (shell_echo(cmd));
  if (strcmp(cmd[0], "exit") == 0)
    return (shell_exit(cmd));
  if (strcmp(cmd[0], "setenv") == 0)
    return (shell_setenv(cmd));
  if (strcmp(cmd[0], "unsetenv") == 0)
    return (shell_unsetenv(cmd));
  if (strcmp(cmd[0], "env") == 0)
    return (shell_env(cmd));
  if (strcmp(cmd[0], "no_match") == 0)
    return (no_match(cmd));
  if (strcmp(cmd[0], "alias") == 0)
    return (mar_alias(cmd));
  if (strcmp(cmd[0], "unalias") == 0)
    return (mar_unalias(cmd));
  return (-1);
}

char    *str_concat(char *str1, char *str2)
{
  char  *u_str;
  int   i;
  int   o;

  i = 0;
  o = 0;
  u_str = malloc(sizeof(char) * (strlen(str1) + strlen(str2)));
  while (str1[i])
    {
      u_str[o] = str1[i];
      i++;
      o++;
    }
  i = 0;
  while (str2[i])
    {
      u_str[o] = str2[i];
      i++;
      o++;
    }
  u_str[o] = '\0';
  return (u_str);
}

void    exec_chevd(t_exe *exe, t_f l, char **env)
{
  int   fd;
  char  *varenv;

  if ((varenv = getvarenv(env, "PATH", 0)) == NULL)
    {
      if (access(str_concat("/bin/", exe[l.i].cmd[0]), F_OK) != 0)
	printf("%s: Command not found.\n", exe[l.i].cmd[0]);
      exe[l.i].cmd[0] = str_concat("/bin/", exe[l.i].cmd[0]);
    }
  else
    if ((exe[l.i].cmd[0] = get_path(varenv, exe[l.i].cmd[0])) == NULL)
      exit(1);
  if (exe[l.i].next == '>')
    fd = open(exe[l.i + 1].cmd[0], O_CREAT | O_WRONLY, 0666);
  else
    fd = open(exe[l.i + 1].cmd[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
  dup2(l.old_fd, 0);
  dup2(fd, 1);
  execve(exe[l.i].cmd[0], exe[l.i].cmd, env);
  exit(1);
}

void    exec_pipe(t_exe *exe, t_f l, int *p, char **env)
{
  char  *varenv;

  if ((varenv = getvarenv(env, "PATH", 0)) == NULL)
    {
      if (access(str_concat("/bin/", exe[l.i].cmd[0]), F_OK) != 0)
	printf("%s: Command not found.\n", exe[l.i].cmd[0]);
      exe[l.i].cmd[0] = str_concat("/bin/", exe[l.i].cmd[0]);
    }
  else
    if ((exe[l.i].cmd[0] = get_path(varenv, exe[l.i].cmd[0])) == NULL)
      exit(1);
  dup2(l.old_fd, 0);
  if (exe[l.i].next == '|')
    dup2(p[1], 1);
  close(p[0]);
  execve(exe[l.i].cmd[0], exe[l.i].cmd, env);
  exit(1);
}

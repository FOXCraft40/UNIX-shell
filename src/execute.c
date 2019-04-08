/*
** execute.c for 42 in /home/hugo/Projet/Sysunix/PSU_2016_42sh/hugo
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Wed Apr 26 09:49:34 2017 Hugo
** Last update Sun May 21 11:16:56 2017 Hugo
*/

#include "42sh.h"

void	exec(char *line, char ***env)
{
  t_exe	*exe;
  t_f	b;

  b.i = 0;
  if ((str_to_cmd(line, &exe) == 84))
    return ;
  while (exe[b.i].cmd[0][0] != '\0')
    {
      if (exe[b.i].next == ';' || exe[b.i].next == '\0')
	{
	  exec_simple(exe[b.i].cmd, env);
	  b.i++;
	}
      else
	{
	  exec_redir(exe, &b, env);
	}
    }
  while (wait(&g_return_value) >= 0);
  print_sig(g_return_value, exe[b.i-1].cmd[0]);
}

void	exec_redir(t_exe *exe, t_f *b, char ***env)
{
  int	p[2];

  b->bool = 0;
  (*b).old_fd = 0;
  while (b->bool != 1)
    {
      if ((pipe(p) == -1))
	exit(84);
      if (exe[b->i].next != '|' && exe[b->i].next != '<' &&
	  exe[b->i].next != '>' && exe[b->i].next != '=')
	b->bool = 1;
      if ((b->pid = fork()) == -1)
      	exit(84);
      exec_scd(&exe, b, &p, env);
      b->i++;
    }
}

void	exec_chevgg(t_exe *exe, t_f l, int *p, char **env)
{
  char	*str;
  int	tmp;
  char	*varenv;

  if ((varenv = getvarenv(env, "PATH", 0)) == NULL)
    {
      printf("Remet les variables d'env fils de pute\n");
      exit(84);
    }
  exe[l.i].cmd[0] = get_path(varenv, exe[l.i].cmd[0]);
  tmp = dup(1);
  dup2(p[1], 1);
  write(tmp, "? ", 2);
  while (((str = get_next_line(0)) != NULL) &&
	 strcmp(str, exe[l.i + 1].cmd[0]) != 0)
    {
      write(tmp, "? ", 2);
      write(p[1], str, strlen(str));
      write(p[1], "\n", 1);
    }
  close(p[1]);
  dup2(tmp, 1);
  dup2(p[0], 0);
  execve(exe[l.i].cmd[0], exe[l.i].cmd, env);
  exit(1);
}

void	exec_chevg(t_exe *exe, t_f l, char **env)
{
  int	fd;
  char	*varenv;
  int	tmp;

  if ((varenv = getvarenv(env, "PATH", 0)) == NULL)
    {
      if (access(str_concat("/bin/", exe[l.i].cmd[0]), F_OK) != 0)
	printf("%s: Command not found.\n", exe[l.i].cmd[0]);
      exe[l.i].cmd[0] = str_concat("/bin/", exe[l.i].cmd[0]);
    }
  else
    if (((exe[l.i].cmd[0] = get_path(varenv, exe[l.i].cmd[0])) == NULL))
      exit(1);
  fd = open(exe[l.i + 1].cmd[0], O_RDONLY);
  tmp = dup(0);
  dup2(fd, 0);
  free(varenv);
  execve(exe[l.i].cmd[0], exe[l.i].cmd, env);
  close(fd);
  dup2(tmp, 0);
  exit(1);
}

void	exec_simple(char **cmd, char ***env)
{
  char	*varenv;
  int	pid;
  int	builtin_ret;
  char	*exec;

  builtin_ret = is_builtin(cmd);
  if (builtin_ret != -1 && (g_return_value = builtin_ret) != -1)
    return ;
  if ((varenv = getvarenv(*env, "PATH", 0)) == NULL)
    {
      if (access(str_concat("/bin/", cmd[0]), F_OK) != 0)
	printf("%s: Command not found.\n", cmd[0]);
      exec = str_concat("/bin/", cmd[0]);
    }
  else if ((exec = get_path(varenv, cmd[0])) == NULL)
    return ;
  if (((pid = fork()) == -1))
    exit(84);
  if (pid == 0)
    {
      execve(exec, cmd, *env);
      exit(1);
    }
  free(varenv);
}

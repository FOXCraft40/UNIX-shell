/*
** shell_cd.c for shell_cd in /home/regisb/Semestre_2/prog_shell/42sh/test
**
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
**
** Started on  Mon Apr 24 11:03:53 2017 Régis Berthelot
** Last update Sun May 21 15:11:01 2017 Régis Berthelot
*/

#include "42sh.h"

static int		cd_forward(char *path)
{
  struct stat		filestat;
  char			pwd[1024];

  stat(path, &filestat);
  if (access(path, F_OK) == -1)
    {
      dprintf(2, "%s: No such file or directory.\n", path);
      return (1);
    }
  if (S_ISDIR(filestat.st_mode) == 0)
    {
      dprintf(2, "%s: Not a directory.\n", path);
      return (1);
    }
  chdir(path);
  getcwd(pwd, sizeof(pwd));
  setenv("PWD", pwd, 1);
  return (0);
}

static int	cd_minus(void)
{
  char		*oldpath;
  int		status;

  oldpath = env_extract("OLDPWD");
  status = cd_forward(oldpath);
  free(oldpath);
  return (status);
}

static int	cd_home(char **args_tab)
{
  char		*path;

  if (tab_length(args_tab) > 2)
    {
      dprintf(2, "cd: Too many arguments.\n");
      return (1);
    }
  if (!args_tab[1] || (args_tab[1] && strcmp(args_tab[1], "--") == 0))
    {
      path = env_extract("HOME");
      if (!path)
	{
	  dprintf(2, "cd: No home directory.\n");
	  return (1);
	}
      chdir(path);
      free(path);
      return (0);
    }
  else if (args_tab[1] && (args_tab[1][0] == '~'))
    {
      dprintf(2, "No $home variable set.\n");
      return (1);
    }
  return (-1);
}

int	shell_cd(char **args_tab)
{
  char	*current_path;
  int	status;

  current_path = getenv("PWD");
  status = cd_home(args_tab);
  if (status < 0)
    {
      if (strcmp(args_tab[1], "-") == 0)
	status = cd_minus();
      else
	status = cd_forward(args_tab[1]);
      if (status == 0)
	setenv("OLDPWD", current_path, 1);
    }
  return (status);
}

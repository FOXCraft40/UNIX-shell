/*
** print_signal.c for 42sh in /home/hugo/Projet/Sysunix/PSU_2016_42sh/hugo
**
** Made by Hugo
** Login   <hugo@epitech.net>
**
** Started on  Thu Apr 27 19:06:19 2017 Hugo
** Last update Sun May 21 14:03:32 2017 Régis Berthelot
*/

#include "42sh.h"

void		print_sig(int sig, char *str)
{
  struct stat	sb;

  if (sig == 256)
    {
      if ((stat(str, &sb) != -1) && ((S_ISDIR(sb.st_mode) ||
				      !(sb.st_mode & S_IXUSR))))
	printf("%s: Permission denied.\n", str);
      else if (stat(str, &sb) != -1)
	printf("%s: Exec format error. Binary file not executable.\n", str);
      g_return_value = 1;
    }
  else if (sig == 139)
    write(2, "Segmentation fault (core dumped)\n", 33);
  else if (sig == 8)
    {
      printf("Floating exception\n");
      g_return_value = 136;
    }
  else if (sig == 134)
    printf("Abort (core dumped)\n");
  else if ((sig == 11) && (g_return_value = 139))
    printf("Segmentation fault\n");
  else if (sig == 136)
    printf("Floating exception (core dumped)\n");
}

void    my_err(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
}

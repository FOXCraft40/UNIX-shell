/*
** reprise.c for 42sh in /home/regisb/Semestre_2/prog_shell/42sh/test
** 
** Made by Régis Berthelot
** Login   <regis.berthelot@epitech.eu>
** 
** Started on  Thu May 11 10:20:50 2017 Régis Berthelot
** Last update Sun May 21 17:38:14 2017 Fernand Matignon
*/

#include "42sh.h"

static void	rdline_setup(t_rdline *rdline)
{
  rdline->timeout.tv_sec = 1;
  rdline->timeout.tv_nsec = 0;
  tcgetattr(STDIN_FILENO, &rdline->old);
  rdline->new = rdline->old;
  rdline->new.c_lflag &= ~(ICANON | ECHO);
  rdline->new.c_cc[VMIN] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &rdline->new);
  sigemptyset(&rdline->sigmask);
  rdline->fds[0].events = POLLIN;
  rdline->fds[0].fd = STDIN_FILENO;
  rdline->count = 0;
  puts("\033[2A");
  write(1, "\0337", 2);
}

static void	rdcompletion(t_rdline *rdline)
{
  char		*str;

  rdline->line[rdline->count] = 0;
  str = fer_auto_c(rdline->line);
  if (str)
    {
      cat_from(rdline->line, str, rdline->count);
      rdline->count = strlen(rdline->line);
      free(str);
    }
}

static int	rdanalyst(t_rdline *rdline)
{
  if (rdline->ret > 0)
    {
      rdline->line[rdline->count + rdline->ret] = '\0';
      if (rdline->line[rdline->count] == '\n')
	{
	  write(1, "\n", 1);
	  rdline->line[rdline->count] = '\0';
	  return (1);
	}
      else if (strcmp((char *)&rdline->line[rdline->count], "\033[A") == 0)
	rd_history(rdline, "up");
      else if (strcmp((char *)&rdline->line[rdline->count], "\033[B") == 0)
	rd_history(rdline, "down");
      else if (rdline->line[rdline->count] == 127)
	{
	  if (rdline->count != 0)
	    rdline->count -= rdline->ret;
	  printf("\033[1K");
	}
      else if (rdline->line[rdline->count] == '\t')
	rdcompletion(rdline);
      else
	rdline->count += rdline->ret;
    }
  return (0);
}

static void	rdloop(t_rdline *rdline)
{
  while (1)
    {
      puts("\0338");
      rdline->fds[0].revents = 0;
      rdline->ret = ppoll(rdline->fds,
			  sizeof(rdline->fds) / sizeof(struct pollfd),
			  &rdline->timeout, &rdline->sigmask);
      if (rdline->fds[0].revents & POLLIN)
      	{
      	  rdline->ret = read(STDIN_FILENO,
			     &rdline->line[rdline->count],
			     sizeof(rdline->line) - rdline->count);
	  if (rdanalyst(rdline) == 1)
	    return ;
      	}
      rdline->line[rdline->count] = '\0';
      printf("\033[2K");
      printf("42sh $ %s", rdline->line);
      fflush(stdout);
      printf("\033[1A");
      printf("\0337");
    }
}

char		*rdline(void)
{
  t_rdline	rdline;
  char		*line;
  size_t	n;
  ssize_t	kek;

  line = NULL;
  if (!isatty(0))
    {
      n = 0;
      if ((kek = getline(&line, &n, stdin) > 0))
	{
	  chomp(line);
	  return (line);
	}
      return (NULL);
    }
  rdline_setup(&rdline);
  rdloop(&rdline);
  tcsetattr(STDIN_FILENO, TCSANOW, &rdline.old);
  line = strdup(rdline.line);
  get_history(0, 1);
  append_to_history(line);
  return (line);
}

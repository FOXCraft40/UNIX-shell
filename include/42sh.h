/*
** 42sh.h for Header 42sh in /home/fox/epitech/PSU_2016_42sh/include
**
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
**
** Started on  Fri Apr 28 14:51:35 2017 Fernand Matignon
** Last update Sun May 21 17:35:41 2017 Fernand Matignon
*/

#ifndef _42SH_H_
# define _42SH_H_

/*
** GLOBALS
*/
extern char	**environ;
int		g_return_value;
char		**g_cmd_hist;
char            **g_alias;

/*
** INCLUDE
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <poll.h>
#include <termios.h>

/*
** STRUCT
*/
typedef struct  s_var
{
  int   o;
  int   i;
  int   a;
  int   y;
}               t_var;

typedef struct  s_exe
{
  char  **cmd;
  char  next;
}               t_exe;

typedef struct  s_f
{
  int   old_fd;
  int   i;
  int	bool;
  pid_t	pid;
}               t_f;

typedef struct  s_rdline
{
  struct timespec       timeout;
  struct termios        old;
  struct termios        new;
  char                  line[128];
  unsigned int          count;
  int                   ret;
  struct pollfd         fds[1];
  sigset_t              sigmask;
}		t_rdline;

/*
** FERNAND SRC
*/
int	fer_mysh();
char	**fer_line_form(char *);
char	**fer_prompt();
void	fer_ctrl_c();
char	*fer_auto_c(char *);
void	my_freetab(char **);
int	shell_env(char **);

/*
** HUGO SRC
*/
char    *get_next_line(const int fd);
void    exec(char *, char ***);
char    **my_malloc(int, int);
int     str_to_cmd(char *, t_exe **);
int     rempstruct(char *, t_exe **, t_var);
int     rempstruct2(t_exe **, t_var *, char *);
void    rempstruct3(t_exe **, t_var *, char *);
t_exe   *mallocstruct(char *, int, int, int);
void    my_aff_tab(char **);
void    my_aff_struct(t_exe *);
char    *get_path(char *, char *);
char    *getvarenv(char **, char *, int);
int     comptnb(char *);
char    *assemblage(char *, char *);
void    exec_simple(char **, char ***);
char    *get_line(char *, int);
char    *my_strcpi(char *);
void    print_sig(int, char *);
void    my_err(char *);
void    exec_redir(t_exe *, t_f *, char ***);
void    exec_pipe(t_exe *, t_f, int *, char **);
void    exec_chevd(t_exe *, t_f, char **);
void    exec_chevg(t_exe *, t_f, char **);
void    exec_chevgg(t_exe *, t_f, int *, char **);
char	*str_concat(char *, char *);
void	exec_scd(t_exe **, t_f *, int (*)[2], char ***);

/*
** MARIUS SRC
*/
int	mar_alias(char **);
int	mar_unalias(char **);
int     star_start(char *, char *);
int     star_end(char *, char *);
int     int_inter(char *);
char	*globing(char *);
void    my_putchar(char);
int	int_inter(char*);
char    **my_sep_to_char(char *, char);
char	**change_inter(char **, int);
int     int_star(char *);
char    **change_star(char **, int);
char	**put_path(char *, char **);
char	**put_alias(char **);
char	**assemble_tab(char **, char **, int);
char	*put_in_str(char **);
void    my_put_tab(char **);
char    *if_name(char *);
char    *if_path(char *);
char    **read_dir(char *);
int     size_malloc(char **);
int     find_alias(char *);
int     my_tablen(char **);
void    realloc_alias(char *);
char    *copy_(char **);
void    swap_str(char **, char **);
int     no_slash(char *);
char    **put_no_match(char **, int);
int     no_match(char **);

/*
** REGIS SRC
*/
char    *rdline(void);
int     tab_length(char **);
void    tab_display(char **);
char    *env_extract(char *);
void    copy_from(char *, char *, int);
void    copy_ft(char *, char *, int, int);
char    *var_extract(char *, int);
char    *line_substitution(char *);
int     total_length(char *, int, int);
int     shell_cd(char **);
int     shell_echo(char **);
int     shell_exit(char **);
int     shell_setenv(char **);
int     shell_unsetenv(char **);
void	chomp(char *);
int	nbr_extract_from(char *, int *);
char	*get_history(int, short);
void	append_to_history(char *);
int	is_builtin(char **);
void	cat_from(char *, char *, int);
void	rd_history(t_rdline *, char *);

/*
** SPYROS SRC
*/
char    **pre_parsing(char *);
char    *fill(char *, int, int);
int     number_of_cases(char *, int);
char    *my_strcpy_xy(char *, int, int);
char    **my_tab_realloc(char **);
int     tablen(char **);

#endif /* !_42SH_H_ */

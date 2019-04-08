##
## Makefile for makefile 42sh in /home/fox/epitech/PSU_2016_42sh
## 
## Made by Fernand Matignon
## Login   <fernand.matignon@epitech.eu>
## 
## Started on  Fri Apr 28 14:44:52 2017 Fernand Matignon
## Last update Sun May 21 17:39:13 2017 Fernand Matignon
##

NAME =		42sh

RM = 		rm -f

CFLAGS += 	-Iinclude -o3 -pedantic -Wall -Wextra

GCC =		gcc

TO_O =		$(SRC:.c=.o)

SRC = 		src/main.c		\
		src/gnl.c		\
		src/tablen.c		\
		src/rdline.c		\
		src/execute.c		\
		src/fer_mysh.c		\
		src/get_path.c		\
		src/shell_cd.c		\
		src/execute2.c		\
		src/no_match.c		\
		src/mar_stars.c		\
		src/mar_alias.c		\
		src/mar_inter.c		\
		src/put_alias.c		\
		src/mar_alias2.c	\
		src/shell_echo.c	\
		src/shell_exit.c	\
		src/mar_stars2.c	\
		src/parse_line.c	\
		src/fer_prompt.c	\
		src/fer_signal.c	\
		src/line_utils.c	\
		src/pre_parsing.c	\
		src/parse_line2.c	\
		src/mar_globing.c	\
		src/mar_unalias.c	\
		src/cmd_history.c	\
		src/shell_setenv.c	\
		src/mar_read_dir.c	\
		src/print_signal.c	\
		src/fer_auto_comp.c	\
		src/tab_functions.c	\
		src/shell_unsetenv.c	\
		src/mar_if_path_name.c	\
		src/string_functions.c	\
		src/number_functions.c	\
		src/line_substitution.c	\
		src/mar_my_sep_to_char.c

all: $(NAME)

$(NAME):$(TO_O)
	@$(GCC) -o $(NAME) $(TO_O)

clean:
	@$(RM) $(TO_O)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 17:24:19 by mberrouk          #+#    #+#              #
#    Updated: 2023/08/03 10:47:24 by mberrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC			=	cc

CFALGS		=	-Wall -Wextra -Werror -g #-fsanitize=address -g3

IDFLAG		=	-I/Users/mberrouk/homebrew/opt/readline/include

LDFLAG		=	-L/Users/mberrouk/homebrew/opt/readline/lib -lreadline

SRCS =  utils/ft_split.c utils/linked_list_utils.c utils/utils_double_ptr.c utils/utils_err.c \
		utils/utils_strings.c utils/utils_strings1.c parsing/lexer.c parsing/parser.c parsing/parsing_utils.c\
		main.c exec_test.c parsing/expansion_analysis.c parsing/expansion_in_doublq.c parsing/expansion_utils.c \
		parsing/expansion_utils2.c parsing/itoa.c env_process.c ft_printf.c clean_utils.c

OBJ = ${SRCS:%.c=%.o}

CC = cc -fsanitize=address -g3 #-Wall -Wextra -Werror  #-lncurses  -L -lreadline -L /Users/mberrouk/homebrew/opt/readline/include/readline -I ~/homebrew/opt/readline/include
CFLAGS = -Wall -Wextra -Werror -lreadline

all : ${NAME}

${NAME} : ${OBJ}
	$(CC) $(CFALGS) $(IDFLAG) $(LDFLAG) -o $@ $^
	make clean
	clear
	#./minishell

%.o : %.c
	$(CC) $(CFALGS) -c $< -o $@ $(IDFLAG)

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

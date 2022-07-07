# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 15:12:04 by acaillea          #+#    #+#              #
#    Updated: 2022/07/07 14:53:29 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./Includes/colors.mk

#------------------------------------------------------------------------------#

NAME	=	minishell

#------------------------------------------------------------------------------#

LIB		= ${LIB_DIR}libft.a

LIB_DIR	= ./Sources/Libft/

#------------------------------------------------------------------------------#

SRC_DIR	= 	./Sources/

SRC		= 	main.c				\
			builtin_launcher.c	\
			builtins.c			\
			enviro.c			\
			execpipe.c			\
			exit.c				\
			ft_cd.c				\
			ft_echo.c			\
			ft_exit.c			\
			ft_free.c			\
			init.c				\
			lst_env.c			\
			lst_env1.c			\
			pars_end.c			\
			pars_dollar.c		\
			pars_tmp_env_var.c	\
			pars_utils.c		\
			pars_init.c			\
			pars.c				\
			pipe_utils.c		\
			pipe_utils2.c		\
			pipe.c				\
			signals.c			\
			tab_utils.c 		\
			utils.c				\
			utils_1.c			\

INC		= 	./Includes/minishell.h

#------------------------------------------------------------------------------#

OBJS	=	${addprefix ${OBJ_DIR}, ${SRC:%.c=%.o}}

OBJ_DIR	= 	./Objects/

#------------------------------------------------------------------------------#

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I/Users/$(USER)/.brew/Cellar/readline/8.1.2/include
RLFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
MK		= mkdir -p
RM		= /bin/rm -f
VEL		= sleep
PRI		= printf

#------------------------------------------------------------------------------#

all :	${NAME}

#------------------------------------------------------------------------------#

${OBJ_DIR}:
	@${MK} ${OBJ_DIR}

${OBJ_DIR}%.o:${SRC_DIR}%.c
	@${CC} -g ${CFLAGS} -I ${INC} -c $< -o $@
	@${PRI} "$		Compiling	minishell :	[${C_ORANGE}$<${C_DEFAUT}]\
	 $(C_RESET) $(L_CLEAR)\r${C_DEFAUT}"
	@${VEL} 0.1
	@printf "$(L_CLEAR)\r"

${NAME}:	${OBJ_DIR} ${OBJS}
	@make -C ${LIB_DIR}
	@${CC} -g ${CFLAGS} ${RLFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@${PRI} "\n[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
	${C_BOLD}$@ - - ---> ${C_GREEN}Successfully built\n${C_DEFAUT}"
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
	${C_BOLD}sheh - -- -------> ${C_GREEN}Ready to sheh\n${C_DEFAUT}"

#------------------------------------------------------------------------------#

clean : clean_minishell clean_libft

clean_minishell :
	@${RM} -r ${OBJ_DIR}
	@${PRI} "$ [${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Minishell Files Deleted \
	\n${C_DEFAUT}"

clean_libft:
	@make clean -C ${LIB_DIR}

#------------------------------------------------------------------------------#

fclean : fclean_minishell fclean_libft

fclean_minishell : clean_minishell
	@${RM} ${NAME}
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Minishell Exe Deleted \
	\n${C_DEFAUT}"

fclean_libft: clean_libft
	@make fclean -C ${LIB_DIR}

re : 	fclean all

#------------------------------------------------------------------------------#

.PHONY : all clean clean_minishell clean_libft fclean fclean_minishell fclean_libft re

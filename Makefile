# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 15:12:04 by acaillea          #+#    #+#              #
#    Updated: 2022/06/15 16:18:10 by hcremers         ###   ########.fr        #
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
			init.c				\
			pars.c				\
			pars_dols_int.c		\
			pars_env_var.c		\
			pars_tmp_env_var.c	\
			pars_end.c			\
			pars_utils.c		\
			tab_utils.c 		\
			lst_env.c			\
			lst_env1.c			\
			utils.c				\
			ft_free.c			\
			exit.c				\
			ft_exit.c			\
			builtins.c			\
			enviro.c			\
			signals.c			\
			pipe.c				\
			pipe_utils.c		\
			pipe_utils2.c		\
			execpipe.c			\
			ft_cd.c				\
			ft_echo.c			\

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
#	@${VEL} 0.5
	@printf "$(L_CLEAR)\r"

${NAME}:	${OBJ_DIR} ${OBJS}
	@make -C ${LIB_DIR}
	@${CC} -g ${CFLAGS} ${RLFLAGS} ${OBJS} ${LIB} -o ${NAME}
	@${PRI} "\n[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
	${C_BOLD}$@ - - ---> ${C_GREEN}Successfully built\n${C_DEFAUT}"
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
	${C_BOLD}sheh - -- -------> ${C_GREEN}Ready to sheh\n${C_DEFAUT}"

#------------------------------------------------------------------------------#

clean :
	@make clean -C ${LIB_DIR}
	@${RM} -r ${OBJ_DIR}
	@${PRI} "$ [${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}minishell Files Deleted \
	\n${C_DEFAUT}"

fclean : clean
	@make fclean -C ${LIB_DIR}
	@${RM} ${NAME}
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}minishell Exe Deleted \
	\n${C_DEFAUT}"

re : 	fclean all

#------------------------------------------------------------------------------#

.PHONY : all clean fclean re

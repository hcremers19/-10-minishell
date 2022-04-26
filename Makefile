# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 15:12:04 by acaillea          #+#    #+#              #
#    Updated: 2022/04/11 15:12:06 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


-include ./Includes/colors.mk

#------------------------------------------------------------------------------#

NAME	=	minishell

#------------------------------------------------------------------------------#

SRC_DIR	= ./Sources/

SRC		= 	main.c			\
			utils.c			\

INC		= 	./Includes/minishell.h

#------------------------------------------------------------------------------#

OBJS	=	${addprefix ${OBJ_DIR}, ${SRC:%.c=%.o}}
OBJ_DIR	= 	./Objects/

#------------------------------------------------------------------------------#

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RLFLAGS = -lreadline

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
	@${CC} -g ${CFLAGS} ${PTFLAG} -I ${INC} -c $< -o $@
#	@${PRI} "$		Compiling	minishell :	[${C_ORANGE}$<${C_DEFAUT}]\
#	 $(C_RESET) $(L_CLEAR)\r${C_DEFAUT}"
#	@${VEL} 0.5
#	@printf "$(L_CLEAR)\r"

${NAME}:	${OBJ_DIR} ${OBJS}
	${CC} -g ${CFLAGS} ${RLFLAGS} ${OBJS} -o ${NAME}
#	@${PRI} "\n[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
#	${C_BOLD}$@ - - ---> ${C_GREEN}Successfully build\n\n${C_DEFAUT}"

#------------------------------------------------------------------------------#

clean :
	@${RM} -r ${OBJ_DIR}
	@${PRI} "\n$ [${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Files Deleted \
	\n\n${C_DEFAUT}"

fclean : 	clean
	@${RM} ${NAME}
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Exe's Deleted \
	\n\n${C_DEFAUT}"

re : fclean all

#------------------------------------------------------------------------------#

.PHONY : all clean fclean re

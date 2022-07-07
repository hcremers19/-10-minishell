# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaillea <acaillea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 14:25:14 by hcremers          #+#    #+#              #
#    Updated: 2022/07/07 14:53:14 by acaillea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../../Includes/colors.mk

#------------------------------------------------------------------------------#

NAME	= libft.a

#------------------------------------------------------------------------------#

SCRS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c

OBJS	= ${addprefix ${OBJS_DIR}, ${SCRS:%.c=%.o}}

OBJS_DIR	= Objects_Libft/

#------------------------------------------------------------------------------#

INC		= libft.h

#------------------------------------------------------------------------------#

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f
VEL		= sleep
PRI		= printf
MK		= mkdir -p

#------------------------------------------------------------------------------#

all:	${NAME}

#------------------------------------------------------------------------------#

${OBJS_DIR}:
	@${MK} ${OBJS_DIR}

${OBJS_DIR}%.o:%.c
	@${CC} -g ${CFLAGS} -I ${INC} -c $< -o $@
	@${PRI} "$		Compiling	libft :	[${C_ORANGE}$<${C_DEFAUT}]\
	 $(C_RESET) $(L_CLEAR)\r${C_DEFAUT}"
	@${VEL} 0.1
	@printf "$(L_CLEAR)\r"

${NAME}: ${OBJS_DIR} ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@ranlib ${NAME}
	@${PRI} "\n[${C_GREEN}✔︎${C_DEFAUT}]${C_DEFAUT}	\
	${C_BOLD}libft - -- ------> ${C_GREEN}Successfully built${C_DEFAUT}"

#------------------------------------------------------------------------------#

clean:
	@${RM} -r ${OBJS_DIR}
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Libft Files Deleted \
	\n${C_DEFAUT}"

fclean:
	@${RM} -r ${OBJS_DIR}
	@${RM} ${NAME}
	@${PRI} "[${C_GREEN}✔︎${C_DEFAUT}]	${C_RED}Libft Library Deleted \
	\n${C_DEFAUT}"

re:	fclean all

#------------------------------------------------------------------------------#

.PHONY:		all clean fclean re

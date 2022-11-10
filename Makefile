# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcremers <hcremers@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 15:12:04 by acaillea          #+#    #+#              #
#    Updated: 2022/11/10 20:30:40 by hcremers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= main.c

OBJS		= $(addprefix $(OBJDIR), $(SRCS:.c=.o))
OBJDIR		= Objects/

CC			= gcc
RM			= rm -f
MKDIR		= mkdir

LIBDIR		= Sources/
LIB			= $(LIBDIR)libsrcs.a

LIBFTDIR	= Sources/libft/
LIBFT		= $(LIBFTDIR)libft.a

CFLAGS		= -Wall -Wextra -Werror

###############################################################################

$(OBJDIR)%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJDIR), $(<:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(LIBDIR)
				make -C $(LIBFTDIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIB) $(LIBFT) -lreadline -o $(NAME)

$(OBJS):		| $(OBJDIR)

$(OBJDIR):		
				$(MKDIR) $(OBJDIR)

clean:
				make clean -C $(LIBDIR)
				make clean -C $(LIBFTDIR)
				$(RM) $(wildcard *.o)
				$(RM) -r $(OBJDIR)

fclean:			clean
				make fclean -C $(LIBDIR)
				make fclean -C $(LIBFTDIR)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

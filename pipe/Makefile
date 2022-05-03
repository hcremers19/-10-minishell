NAME	=	pipe
PROG	=	pipe

SRCS =	pipe.c \
		pipe_utils.c \
		pipe_utils2.c \
		pipe_utils3.c \
		minilibft.c 
				
OBJS	=	${SRCS:.c=.o}
MAIN	=	pipex.c

INCLUDE = pipex.h

CC	=	gcc

FLAGS	=	-Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
	${CC} ${FLAG} -o $(NAME) $(OBJS)

clean:
		rm -f ${OBJS}

fclean:	clean
			rm -f ${NAME}

re: fclean all

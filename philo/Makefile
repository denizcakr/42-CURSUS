CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = philo
SRCS = init.c main.c utils.c utils2.c start.c control_die_and_eat.c

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all: ${NAME}

clean:

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
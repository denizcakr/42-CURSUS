# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezcakir <ezcakir@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 18:59:39 by ezcakir           #+#    #+#              #
#    Updated: 2023/09/13 19:38:11 by ezcakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

CFILES_1 = push_swap.c

CFILES_2 = function.c \
			function2.c \
			function3.c \
			rules_a.c \
			rules_b.c \
			utils.c \
			utils2.c

BONUS_FILES = checker.c get_next_line.c

OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)

BONUS_OBJS = $(BONUS_FILES:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFTM) -o $(NAME)
	@echo "\n\033[33mPush_swap is ready ✅\033[0m\n"

$(BONUS_NAME): $(BONUS_OBJS) $(OBJS_2) 
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) $(LIBFTM) -o $(BONUS_NAME)
	@echo "\n\033[33mChecker is ready ✅\033[0m\n"

all: $(NAME) $(BONUS_NAME)
	@echo "\n\033[33mAll files compiled successfully ✅\033[0m\n"

bonus: ${BONUS_NAME} 
	@echo "\n\033[33mBonus files compiled successfully ✅\033[0m\n"	

clean: pic
		@rm -f $(OBJS_1) $(OBJS_2) $(BONUS_OBJS)
		@echo "\n\033[33mObjects files deleted ✅\033[0m\n"

fclean: clean
		@rm -rf $(NAME) $(BONUS_NAME)
		@echo "\n\033[33mArchive file deleted ✅\033[0m\n"

re: fclean all

pic :
		@echo "\033[1;33m     .--..--..--..--..--..--.			"
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 14:41:03 by emanuela          #+#    #+#              #
#    Updated: 2023/02/03 18:48:29 by emlicame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo
INC		:=	-I includes
HEADERS	:=	includes/philo.h 	\
			includes/colors.h 	\
			includes/ph_defines.h
SRC		:=	main.c 				\
			data_init.c 		\
			threads_create.c 	\
			mutex_lock_unlock.c \
			time.c				\
			routine.c 			\
			life_check.c		\
			print.c
OBJ		:= $(SRC:%.c=obj/%.o)
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
# CFLAGS 	+= -fsanitize=address
# CFLAGS 	+= -fsanitize=thread

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

all:	$(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) ${OBJ} $(INC) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Philo Done$(RESET)"

obj/%.o: src/%.c $(HEADERS)
	@mkdir -p obj
	@$(CC) $(INC) $(CFLAGS) -o $@ -c $<
	
clean:
	@rm -f $(OBJ) 
	@rm -rf obj
	@echo "$(GREEN)$(BOLD)Philo clean$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
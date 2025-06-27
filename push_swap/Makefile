# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 10:35:54 by ppassos           #+#    #+#              #
#    Updated: 2024/10/07 11:04:32 by ppassos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

CC = cc $(FLAGS)

CFILES = main.c aux_1.c error_checker.c ft_atol.c ft_split.c \
	push_comand.c rotate_comand.c stack_init.c swap_comand.c algoritm.c \
	index.c checker.c list.c

RM = rm -rf

OBJECTS = $(CFILES:.c=.o)

	
$(NAME): $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS)
	
all: $(NAME)

re: fclean all

exec:
	$(CC) $(CFILES) -lbsd

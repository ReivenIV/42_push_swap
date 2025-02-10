# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rita <rita@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:49:37 by rita              #+#    #+#              #
#    Updated: 2025/02/10 17:49:37 by rita             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = algo_random_amount.c instructs_rotate.c \
tools_for_TESTING.c algo_3_nbs.c error_handler.c instructs_rotate_reverse.c \
stack_init.c tools_get_stack.c algo_4_nbs.c ft_atol.c instructs_swap.c \
tools_misc_stack.c algo_5_nbs.c ft_split.c main.c tools_3_nbs.c \
tools_move_stack.c algo_handler.c instructs_push.c tools_data_stack.c \
tools_push_stack.c \

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Executable $(NAME) created successfully"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJS)
	@echo ".o files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable $(NAME) cleaned."

re: fclean all

.PHONY: all clean fclean re
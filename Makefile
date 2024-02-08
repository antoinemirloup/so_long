# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:12:26 by amirloup          #+#    #+#              #
#    Updated: 2024/02/08 15:15:56 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3 -fsanitize=address
LIBMLX	= ./MLX42
SRCS = main.c map/map_check.c map/path_check1.c map/path_check2.c map/utils1.c \
	mlx/open_window.c

LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS =	$(SRCS:.c=.o)

RM = @rm -rf

RED = \e[1;91m
GREEN = \e[1;92m
YELLOW = \e[1;93m
		
all:	libmlx $(NAME)
	@echo "$(RED)o---------------o"
	@echo "$(RED)| $(GREEN)  ./so_long   $(RED)|"
	@echo "$(RED)o---------------o"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	
$(NAME): $(OBJS)
	@make --no-print-directory -C libft
	@make --no-print-directory -C printf
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a printf/libftprintf.a $(LIBS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make --no-print-directory -C libft clean
	@make --no-print-directory -C printf clean
		
fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@rm -rf $(LIBMLX)/build
	@make --no-print-directory -C libft fclean
	@make --no-print-directory -C printf fclean
				
re:		fclean all

ex:		re clean
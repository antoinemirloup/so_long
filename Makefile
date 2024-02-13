# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:12:26 by amirloup          #+#    #+#              #
#    Updated: 2024/02/13 15:16:39 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3# -fsanitize=address

SRCS = main.c map/map_check.c map/path_check1.c map/path_check2.c map/utils1.c map/map_pix.c \
	mlx/open_window.c mlx/destroy.c mlx/player.c mlx/background.c mlx/walls.c mlx/exit.c \
	mlx/check_collision.c mlx/collectible.c

LIBS	= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS =	$(SRCS:.c=.o)

RM = @rm -rf

RED = \e[1;91m
GREEN = \e[1;92m
YELLOW = \e[1;93m
		
all:	$(NAME)
	@echo "$(RED)o---------------o"
	@echo "$(RED)| $(GREEN)  ./so_long   $(RED)|"
	@echo "$(RED)o---------------o"
	
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
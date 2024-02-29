# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:12:26 by amirloup          #+#    #+#              #
#    Updated: 2024/02/29 13:57:28 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g3 #-fsanitize=address

SRCS = main.c \
	map/map_check.c \
	map/path_check1.c \
	map/path_check2.c \
	map/utils1.c \
	game/open_window.c \
	game/destroy.c \
	game/destroy_images.c \
	game/player.c \
	game/background.c \
	game/walls.c \
	game/exit.c \
	game/success.c \
	game/check_collision.c \
	game/collectibles/collectible.c \
	game/collectibles/delete_collectibles.c \
	game/collectibles/load_collectibles.c \
	game/fog/set_fog.c \
	game/fog/fog.c \
	game/counter/counter.c \
	game/counter/counter_unit.c \
	game/counter/counter_ten.c \
	game/counter/counter_hundred.c \
	game/counter/counter_utils.c \
	game/moves.c \
	game/animations.c \
	game/enemies/enemies.c \
	game/enemies/move_enemies.c \
	game/enemies/move_enemy_1.c \
	game/enemies/move_enemy_2.c \
	game/death/load_death.c \
	game/death/death.c \
	game/result.c \
	game/init_textures.c

LIBS	= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
OBJS =	$(SRCS:.c=.o)

RM = @rm -rf

CURRENT_DATE = $(shell date +"%Y-%m-%d %H:%M")

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

git: 
	@git add . > /dev/null 2>&1
	@git commit -m "$(CURRENT_DATE)" > /dev/null 2>&1 || echo "$(GREEN) GIT ALREADY UP TO DATE"
	@git push > /dev/null 2>&1
	@echo "$(GREEN) GIT UPDATE WAS A HUGE SUCCESS!"
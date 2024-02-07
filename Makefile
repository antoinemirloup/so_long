# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:12:26 by amirloup          #+#    #+#              #
#    Updated: 2024/02/07 11:00:06 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 
SRCS = main.c map_check.c path_check1.c path_check2.c utils1.c 

INCLUDE = so_long.h

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
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a printf/libftprintf.a -o $(NAME)

clean :
	$(RM) $(OBJS)
	@make --no-print-directory -C libft clean
	@make --no-print-directory -C printf clean
		
fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@make --no-print-directory -C libft fclean
	@make --no-print-directory -C printf fclean
				
re:		fclean all

ex:		re clean
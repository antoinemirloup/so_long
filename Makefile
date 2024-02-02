# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:12:26 by amirloup          #+#    #+#              #
#    Updated: 2024/02/02 14:56:46 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
SRCS = map_check.c utils1.c

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
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean :
	$(RM) $(OBJS)
	@make --no-print-directory -C libft clean
		
fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)
	@make --no-print-directory -C libft fclean
				
re:		fclean all

ex:		re clean
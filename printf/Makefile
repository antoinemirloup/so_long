# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:51:36 by amirloup          #+#    #+#              #
#    Updated: 2024/02/06 13:29:15 by amirloup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRCS = 	ft_printf.c\
		ft_printother.c\
		ft_printnb.c\
		ft_printunb.c\
		ft_printptr.c\
		ft_printhex.c
		
OBJS =	${SRCS:.c=.o}

CC =	@cc
CFLAGS = -Wall -Werror -Wextra
RM =	@rm -f

${NAME}:	${OBJS}
		@ar rcs ${NAME} ${OBJS}

all:	${NAME}
			
clean :
		${RM} ${OBJS}
		
fclean: clean
		${RM} ${NAME}
		
re:		fclean ${NAME}

.PHONY:	all bonus clean fclean re
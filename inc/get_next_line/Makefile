# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyakuben <yyakuben@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 19:07:18 by yyakuben          #+#    #+#              #
#    Updated: 2024/05/02 21:25:33 by yyakuben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	get_next_line.c get_next_line_utils.c\


OBJS	=	${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):  $(OBJS)
				ar rcs $@ $^

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
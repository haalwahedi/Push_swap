# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halwahed <halwahed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 11:36:28 by halwahed          #+#    #+#              #
#    Updated: 2022/04/26 10:16:33 by halwahed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -g -Wall -Wextra -Werror -I $(HEADER)

SRCS =	*.c

OBJECTS = $(SRCS:%.c=%.o)

CC = gcc

REM = rm -rf

HEADER = ./

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(REM) $(OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

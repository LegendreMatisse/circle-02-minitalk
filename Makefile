# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:33:04 by mlegendr          #+#    #+#              #
#    Updated: 2023/09/22 15:18:18 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = client.c server.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

#LIBFT_PATH: ./libft
#LIBFT: $(LIBFT_PATH)/libft.a

#PRINTF_PATH: ./printf
#printf: $(PRINTF_PATH)/libftprintf.a

all: server client
#bonus server_bonus client_bonus

server: server.o libft printf
		$(CC) -o $@ server.o -Lprintf -lftprintf

client: client.o libft printf
		$(CC) -o $@ client.o -Lprintf -lftprintf

%.o: %.c
		$(CC) -c $(CFLAGS) $?

libft:
		make -C libft

printf:
		make -C printf

clean:
		rm -f $(OBJECTS)
		make -C libft clean
		make -C printf clean

fclean: clean
		rm -f server client libft/libft.a printf/libftprintf.a

re: fclean all

.PHONY: all libft printf clean fclean re


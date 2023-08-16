# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 18:33:04 by mlegendr          #+#    #+#              #
#    Updated: 2023/08/16 19:18:30 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = minitalk_test_02_client.c minitalk_test_02_server.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

#LIBFT_PATH: ./libft
#LIBFT: $(LIBFT_PATH)/libft.a

#PRINTF_PATH: ./printf
#printf: $(PRINTF_PATH)/libftprintf.a

all: server client
#bonus server_bonus client_bonus

server: minitalk_test_02_server.o libft printf
		$(CC) -o $@ minitalk_test_02_server.o -Lprintf -lftprintf -v

client: minitalk_test_02_client.o libft printf
		$(CC) -o $@ minitalk_test_02_client.o -Lprintf -lftprintf -v

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


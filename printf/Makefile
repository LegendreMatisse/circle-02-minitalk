# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 17:23:32 by mlegendr          #+#    #+#              #
#    Updated: 2023/06/02 16:13:21 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

SRCS = ./ft_printf.c \
				./ft_hexconvert.c \
				./ft_printstr.c \
				./ft_printnbr.c \
				./ft_uitoa.c \
				./ft_printptr.c

OBJ_DIR                 =       obj
OBJS                    =       $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH              =       ./libft
LIBFT                   =       $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:         %.c
										$(CC) $(CFLAGS) -c $< -o $@

all:                            $(NAME)

$(NAME):                        $(LIBFT) $(OBJ_DIR) $(OBJS)
										cp $(LIBFT) $(NAME)
										$(AR) $(NAME) $(OBJS)

$(LIBFT):
										make -C $(LIBFT_PATH) all

$(OBJ_DIR):
										mkdir -p $(OBJ_DIR)

clean:
										make -C $(LIBFT_PATH) clean
										$(RM) $(OBJ_DIR)

fclean:								clean
										make -C $(LIBFT_PATH) fclean
										$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

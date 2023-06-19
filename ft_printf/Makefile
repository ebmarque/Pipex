# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 10:38:38 by ebmarque          #+#    #+#              #
#    Updated: 2023/04/27 12:41:30 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_print_char.c ft_print_int.c \
	ft_print_lowhex.c ft_print_mem.c ft_print_percent.c \
	ft_print_str.c ft_print_upperhex.c ft_print_usgdec.c \

OBJS = ${SRCS:.c=.o}

RM = rm -f
INCLUDE = -I ./
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME): ${OBJS}
		${MAKE} ${LIBFT_PATH} all
		cp ${LIBFT} ${NAME}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re bonus
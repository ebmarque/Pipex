# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 10:38:38 by ebmarque          #+#    #+#              #
#    Updated: 2023/05/27 15:29:37 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = pipex.a

PROGRAM = pipex

PROGRAM_BONUS = pipex_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c pipex_utils.c

SRCS_BONUS = pipex_utils_bonus.c pipex_bonus.c pipex_utils.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

RM = rm -rf
INCLUDE = -I ./
MAKE = make -C
LIBFT_PATH = ft_printf
LIBFT = ${LIBFT_PATH}/libftprintf.a

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

$(PROGRAM): ${LIBRARY}
	@${CC} ${CFLAGS} ${SRCS} -o ${PROGRAM} ${LIBRARY}

$(PROGRAM_BONUS): ${LIBRARY}
	@${CC} ${CFLAGS} ${SRCS_BONUS} -o ${PROGRAM_BONUS} ${LIBRARY}

$(LIBRARY): ${OBJS} ${OBJS_BONUS}
	@${MAKE} ${LIBFT_PATH} all
	@cp ${LIBFT} ${LIBRARY}
	@ar rcs ${LIBRARY} ${OBJS} ${OBJS_BONUS}

all:	${PROGRAM}

bonus:	${PROGRAM_BONUS}

clean:
	@${MAKE} ${LIBFT_PATH} clean
	@${RM} ${OBJS} ${LIBRARY} ${OBJS_BONUS}

fclean: clean
	@${MAKE} ${LIBFT_PATH} fclean
	@${RM} ${PROGRAM} ${PROGRAM_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klaksi <klaksi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 16:24:41 by rmarceau          #+#    #+#              #
#    Updated: 2023/04/04 16:39:50 by klaksi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC_DIR = include
SRCS_DIR = src
OBJS_DIR = objs

SRCS = so_long.c parsing.c build.c graphic.c hook.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/include

MLX_PATH = MLX42/build
MLX_LIB = ${MLX_PATH}/libmlx42.a
MLX_INC = -Iinclude -lglfw -L"/Users/${USER}/.brew/opt/glfw/lib/"
MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

GREEN	= \033[32;1m
CYAN	= \033[36;1m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m
MAGENTA	=\033[0;95m

all: ${MLX_LIB} ${LIBFT_LIB} ${NAME}

${MLX_LIB}:
	@cd MLX42 && cmake -B build
	@cmake --build ${MLX_PATH} -j4

${LIBFT_LIB}:
	@make -C ${LIBFT_PATH}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${MLX_FLAGS} ${MLX_INC} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}
	@echo "$(GREEN)Compilation terminé avec succès !"

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${OBJS_DIR}
	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	@${RM} ${NAME}

re: fclean all
	@echo "$(CYAN)Recompilation Terminé !"

.PHONY: all clean fclean re
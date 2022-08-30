# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 17:31:55 by ycornamu          #+#    #+#              #
#    Updated: 2022/08/30 13:01:09 by ycornamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = main.c
SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = includes

LIBFT = libft.a
LIBFT_DIR = libft

CC = clang
DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
    MLX_DIR = minilibx_linux
    CFLAGS = -I $(HEADERS) -I $(MLX_DIR) -I $(LIBFT_DIR) -Wall -Wextra -Werror
    LFLAGS = $(CFLAGS) -lmlx -lXext -lX11 -lm -L $(MLX_DIR)
    DEBUG_LFLAGS = -static-libasan
endif
ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx_osx
	CFLAGS = -I $(HEADERS) -I $(MLX_DIR) -I $(LIBFT_DIR) -Wall -Wextra -Werror
	LFLAGS = $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L $(MLX_DIR)
	DEBUG_LFLAGS = ""
endif

.PHONY : all mlx mlx_clean debug clean fclean re

all: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(_OBJS)
	$(CC) $(_OBJS) $(LIBFT_DIR)/$(LIBFT) $(LFLAGS) -o $(NAME)

$(_OBJS): $(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(DIRS) $(LIBFT_DIR)/$(LIBFT) mlx
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all
	$(MAKE) -C $(LIBFT_DIR) bonus
	#cp $(LIBFT_DIR)/libft.h $(HEADERS)/libft.h

mlx:
	@echo "=========== Compiling MinilibX ==========="
	$(MAKE) -C $(MLX_DIR)
ifeq ($(UNAME), Darwin)
	cp $(MLX_DIR)/libmlx.dylib libmlx.dylib
endif
#	cp $(MLX_DIR)/mlx.h $(HEADERS)/mlx.h
	@echo "========= End Compiling MinilibX ========="

mlx_clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f libmlx.dylib
#	rm -f $(HEADERS)/mlx.h

$(DIRS):
	mkdir -p $(DIRS)

clean: mlx_clean
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: mlx_clean
	rm -rf $(OBJS_DIR) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

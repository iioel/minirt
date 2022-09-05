# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 17:31:55 by ycornamu          #+#    #+#              #
#    Updated: 2022/08/30 18:12:59 by ycornamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = main.c \
	   clean.c \
	   window.c \
	   catch_win.c \
	   catch_key.c \
	   catch_mouse.c \
	   mlx_utils.c\
	   gnl.c\
	   parsing.c\
	   object.c
SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = includes

LIBFT = libft.a
LIBFT_DIR = libft
MLX =

MAKE = make --no-print-directory
CC = clang
DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

UNAME = $(shell uname -s)

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

ifeq ($(UNAME), Linux)
    MLX_DIR = minilibx_linux
    CFLAGS = -I $(HEADERS) -I $(MLX_DIR) -I $(LIBFT_DIR)/inc -Wall -Wextra -Werror
    LFLAGS = $(CFLAGS) -lmlx -lXext -lX11 -lm -L $(MLX_DIR)
	MLX_LIB = $(MLX_DIR)/libmlx.a
    DEBUG_LFLAGS = -static-libasan
endif
ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx_osx
	MLX_LIB = $(MLX_DIR)/libmlx.dylib
	CFLAGS = -I $(HEADERS) -I $(MLX_DIR) -I $(LIBFT_DIR)/inc -Wall -Wextra -Werror
	LFLAGS = #$(CFLAGS) -lmlx -framework OpenGL -framework AppKit -L $(MLX_DIR)
	DEBUG_LFLAGS = ""
endif


all: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(MLX_LIB) $(_OBJS)
	@$(CC) $(_OBJS) $(LIBFT_DIR)/$(LIBFT) $(LFLAGS) $(MLX_LIB) -o $(NAME)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c $(DIRS)
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(_CLEAR)"

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)
ifeq ($(UNAME), Darwin)
	@cp $(MLX_DIR)/libmlx.dylib libmlx.dylib
endif

mlx_clean:
	@$(MAKE) -C $(MLX_DIR) clean
	@rm -f libmlx.dylib

$(DIRS):
	@mkdir -p $(DIRS)

clean: mlx_clean
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(_CLEAR)"

fclean: mlx_clean
	@rm -rf $(OBJS_DIR) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all

.PHONY : all mlx mlx_clean debug clean fclean re

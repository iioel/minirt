# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalthaus <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 01:48:48 by yalthaus          #+#    #+#              #
#    Updated: 2022/10/18 16:51:07 by ycornamu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#Name of archive
NAME 	= libft.a

#compiler option
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -Ofast -Wno-unused-result
HEADS	= -I$(INC)

#src
SRCNAMES		=	ft_isalpha.c\
					ft_memcmp.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_atoi.c\
					ft_isascii.c\
					ft_strdup.c\
					ft_tolower.c\
					ft_bzero.c\
					ft_isdigit.c\
					ft_memcpy.c\
					ft_strlcpy.c\
					ft_toupper.c\
					ft_calloc.c\
					ft_isprint.c\
					ft_memmove.c\
					ft_strlen.c\
					ft_isalnum.c\
					ft_memset.c\
					ft_strncmp.c\
					ft_memchr.c\
					ft_strlcat.c\
					ft_strnstr.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putnbr_fd.c\
					ft_putendl_fd.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_split.c\
					ft_itoa.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_realloc.c\
					ft_isinset.c\
					ft_isspace.c\
					skip_space.c\
					ft_atof.c\
					ft_atox.c\
					ft_sscanf.c\
					ft_sscanf_skip.c\
					ft_sscanf_scan.c
BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
SRCDIR 		= ./src/
INC			= ./inc/
BUILDDIR	= ./build/
SRCS		= $(addprefix $(SRCDIR), $(SRCNAMES))
SRCSBONUS	= $(addprefix $(SRCDIR), $(BONUS))

#objs
OBJS			= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))
BONUS_OBJS		= $(addprefix $(BUILDDIR), $(BONUS:.c=.o))

#cmd
RM		= rm -rf
MKDIR	= mkdir -p

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

# build
all: ${NAME}

bonus: $(NAME) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

${NAME} .SILENT: $(BUILDDIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(BUILDDIR)%.o:$(SRCDIR)%.c
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@$(CC) -c $(CFLAGS) $(HEADS) $< -o $@
	@echo "$(_CLEAR)"

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(BUILDDIR)
	@echo "$(_CLEAR)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all
.PHONY 	: 	all clean fclean re bonus

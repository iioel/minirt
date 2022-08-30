
MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

all: $(NAME)

$(NAME) .SILENT: $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@echo "$(_OK) $(NAME) \tcompiled"
	@swiftc $(OPTI) $(INC) -o $(NAME) -emit-library -suppress-warnings  $(OBJ) $(C_OBJ) -lz

%.o: %.swift
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@swiftc $(OPTI) $(INC) -parse-as-library -suppress-warnings -c $< -o $@
	@echo "$(_CLEAR)"

%.swiftmodule: %.swift
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@swiftc $(OPTI) $(INC) -parse-as-library -suppress-warnings -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)
	@echo "$(_CLEAR)"

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@echo "$(_CLEAR)"
	@echo "$(_RM) $(NAME) \tfull clean"


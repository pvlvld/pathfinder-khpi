NAME = pathfinder
LIBMX = libmx/libmx.a

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -O2 -march=native

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIBMX_DIR = libmx

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME): $(LIBMX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBMX_DIR) -lmx -o $@

$(LIBMX):
	make -C $(LIBMX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBMX_DIR)/inc -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	make -C $(LIBMX_DIR) clean
	rm -rf $(OBJ_DIR)

uninstall: clean
	make -C $(LIBMX_DIR) uninstall
	rm -f $(NAME)

reinstall: uninstall all
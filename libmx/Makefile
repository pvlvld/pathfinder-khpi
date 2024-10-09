NAME = libmx.a
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -O2 -march=native
AR = ar rcs

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all libmx uninstall clean reinstall

all: libmx

libmx: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

uninstall: clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ_DIR)

reinstall: uninstall all
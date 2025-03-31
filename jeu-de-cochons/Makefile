CC = gcc
CFLAGS = -Wall -Wextra -g -pedantic -Werror -O2 -std=c11 -Wunused -Wformat=2 -ftrapv -fstack-protector-all -D_FORTIFY_SOURCE=2 -Wconversion -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes
SRC_DIR = src
OBJ_DIR = obj
EXEC = jeu_de_cochons

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
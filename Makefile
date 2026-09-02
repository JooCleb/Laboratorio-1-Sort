CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

TARGET = $(BIN_DIR)/lab_ordenacao

all: create_bin $(TARGET)

create_bin:
	mkdir -p $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean create_bin
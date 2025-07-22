CC = gcc
CFLAGS = -Wall -Wextra -Iinc
LDFLAGS = 
TARGET = application

SRC_DIR = src
INC_DIR = inc
APP_DIR = app

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
APP_FILES = $(wildcard $(APP_DIR)/*.c)

OBJ_FILES = $(SRC_FILES:.c=.o) $(APP_FILES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
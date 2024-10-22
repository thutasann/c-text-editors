# Compiler
CC = gcc

# C Flags
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Source directories
SRC_DIR = src
FIRST_EDITOR_DIR = $(SRC_DIR)/first-editor
SHARED_DIR = $(SRC_DIR)/shared

# Output binary/executable name
TARGET = program

# Rule to compile and link the files for a specific project
all: $(TARGET)

$(TARGET): $(wildcard $(FIRST_EDITOR_DIR)/*.c) $(wildcard $(SHARED_DIR)/*.c)
	$(CC) $(CFLAGS) -o $(TARGET) $(wildcard $(FIRST_EDITOR_DIR)/*.c) $(wildcard $(SHARED_DIR)/*.c) -lncurses

# Rule to run the compiled program for a specific project
run: all
	./$(TARGET)

# Clean up the compiled binary
clean:
	rm -f $(TARGET)

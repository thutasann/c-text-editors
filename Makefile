# Compiler
CC = gcc

# C Flags
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Source directories
SRC_DIR = src
# SHARED_DIR = $(SRC_DIR)/shared

# Default project directory (can be overridden)
PROJECT = first-editor
PROJECT_DIR = $(SRC_DIR)/$(PROJECT)

# Output binary/executable name
TARGET = $(PROJECT)

# Rule to compile and link the files for a specific project
all: $(TARGET)

$(TARGET): $(wildcard $(PROJECT_DIR)/*.c)
	$(CC) $(CFLAGS) -o $(TARGET) $(wildcard $(PROJECT_DIR)/*.c) -lncurses

# Rule to run the compiled program for a specific project
run: all
	./$(TARGET)

# Clean up the compiled binary
clean:
	rm -f $(TARGET)

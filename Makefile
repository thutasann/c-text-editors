# Compiler
CC = gcc

# C Flags
# CFLAGS = -Wall -Wextra -pedantic -std=c99

# Source folder and shared folder
SRC_DIR = src
SHARED_DIR = $(SRC_DIR)/shared

# Output binary/executable name
TARGET = program

# Rule to compile and link the files for a specific project
all: $(PROJECT)

$(PROJECT):
	$(CC) $(wildcard $(SRC_DIR)/$(PROJECT)/*.c) $(wildcard $(SHARED_DIR)/*.c) -o $(TARGET)

# Rule to run the compiled program for a specific project
run: all
	./$(TARGET)

# Clean up the compiled binary
clean:
	rm -f $(TARGET)

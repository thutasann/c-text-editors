# Compiler
CC = gcc

# C Flags
CFLAGS=-Wall -Wextra -pedantic -std=c99

# Source files (index.c and all .c files in src folder)
SRC = index.c src/*.c

# Output binary/executable name
TARGET = index

# Rule to compile and link the files
all:
	clear
	$(CC) $(SRC) -o $(TARGET)

# Rule to run the compiled program
run: all 
	./$(TARGET)

# Clean up the compiled binary
clean:
	rm -f $(TARGET)
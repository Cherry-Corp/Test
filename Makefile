# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Iinclude
LIBS = -lcomdlg32 #-lole32 -luuid -lcomdlg32 -lgdi32

# Source and output
SRC = src/*.c
Iinclude = include/password_generator.h
OUT = main.exe

# Default target: compile
all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LIBS)

# Run the program
run: all
	./$(OUT)

# Clean build files (Windows)
clean:
	del /Q $(OUT)
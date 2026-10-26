.RECIPEPREFIX := >

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# CS50 library
CS50_CFLAGS = -I/usr/local/include
CS50_LIBS = -L/usr/local/lib -lcs50

# GTK library
GTK_CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
GTK_LIBS = $(shell pkg-config --libs gtk+-3.0)

# Default target
all: calculator calculator_gui

# Normal C program
%: %.c
>$(CC) $(CFLAGS) $(CS50_CFLAGS) $< -o $@ $(CS50_LIBS)

# GUI calculator
calculator_gui: calculator_gui.c
>@echo "Building calculator_gui..."
>@if $(CC) $(CFLAGS) $(GTK_CFLAGS) calculator_gui.c -o calculator_gui $(GTK_LIBS); then \
>    echo "Build successful: calculator_gui"; \
>else \
>    echo "Build failed: calculator_gui"; \
>    exit 1; \
>fi

# Clean executable files
clean:
>rm -f calculator calculator_gui

.PHONY: all clean
# Compiler settings
C = clang
CFLAGS = -std=c17 -Wall -Wextra -pedantic -Werror

# Path 
LIB = lib/
SRC = src/
IN = include/

# To compile
OBJECTS = $(LIB)is_prime.o
BINS = main

all: $(BINS)

$(LIB)is_prime.o: $(SRC)is_prime.c $(IN)is_prime.h
	$(C) -c $(CFLAGS) $< -o $@

main: main.c $(OBJECTS)
	$(C) $(CFLAGS) $< $(OBJECTS) -o $@

clean:
	rm $(OBJECTS) $(BINS)


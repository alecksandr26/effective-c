# We need to define the different ways to compile depending the phase of programming
C = clang
CP = clang++

# For programming purpuse
CFLAGS = -std=c17 -pedantic -fno-stack-protector

# For debuging purpuse 
CFLAGS_DEBUG = -std=c17 -O -Wall -Werror -ggdb -pedantic -D_FORTIFY_SOURCE=2

# For testing purpuse
CFLAGS_TEST = -std=c17 -O3 -pedantic -D_FORTIFY_SOURCE=2

# For development purpuse
CFLAGS_BUILD = -std=c17 -O3 -fno-stack-protector

# For the google testing framework we need put the flags "-lgtest" and "-lgtest_main"
CPFLAGS = -std=c++17 -O3 -pedantic -D_FORTIFY_SOURCE=2 -lgtest -lgtest_main

# Defining the paths
SRC = src
LIB = lib
IN = include
TES = test

# All the executable bins 
BINS = main $(TES)/unit_test $(TES)/random_tests build $(TES)/google_test

# All the components
OBJS = $(LIB)/stats.o
OBJS_DEBUG = $(LIB)/stats_debug.o
OBJS_TEST = $(LIB)/stats_test.o
OBJS_BUILD = $(LIB)/stats_build.o


# To compile all the phases
all: $(BINS)

# All the objects
$(LIB)/stats.o: $(SRC)/stats.c $(IN)/stats.h
	$(C) $(CFLAGS) -c $< -o $@

$(LIB)/stats_debug.o: $(SRC)/stats.c $(IN)/stats.h
	$(C) $(CFLAGS_DEBUG) -c $< -o $@

$(LIB)/stats_test.o: $(SRC)/stats.c $(IN)/stats.h
	$(C) $(CFLAGS_TEST) -c $< -o $@

$(LIB)/stats_build.o: $(SRC)/stats.c $(IN)/stats.h
	$(C) $(CFLAGS_BUILD) -c $< -o $@ 

# The main program
main: main.c $(OBJS)
	$(C) $(CFLAGS) $< $(OBJS) -o $@

# Binary to run the test
$(TES)/unit_test: $(TES)/unit_test.c $(OBJS_DEBUG)
	$(C) $(CFLAGS_DEBUG) $< $(OBJS_DEBUG) -o $@

# Black box testing
$(TES)/random_tests: $(TES)/random_tests.c $(OBJS_TEST)
	$(C) $(CFLASG_TEST) $< $(OBJS_TEST) -o $@

$(TES)/google_test: $(TES)/google_test.cpp $(OBJS_TEST)
	$(CP) $(CPFLAGS) $< $(OBJS_TEST) -o $@

# Now we are going to use a framework to test google test


# To compile the deployment program
build: main.c $(OBJS_BUILD)
	$(C) $(CFLAGS_BUILD) $< $(OBJS_BUILD) -o $@

# To run the program in different ways
run_main:
	./main

run_build:
	./build

run_tests:
	./$(TES)/unit_test
	./$(TES)/random_tests


run_unit_test:
	./$(TES)/unit_test

run_random_tests:
	./$(TES)/random_tests

run_google_test:
	./$(TES)/google_test


# To clean the project
clean:
	rm $(OBJS) $(OBJS_DEBUG) $(OBJS_TEST) $(BINS)



#define base dir path
MAKE_DIR=$(shell pwd)
WORK_DIR=$(subst /make,,$(MAKE_DIR))
SRC_DIR=$(WORK_DIR)/src
INCLUDE_DIR=$(WORK_DIR)/include

#define objects
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJECTS=$(subst $(SRC_DIR)/,,$(SRCS:.c=.o))

#include other .config
-include .config

#test is default Goal
test: output.o input.o main.o
	$(CC) -I $(INCLUDE_DIR) -o $@ $^

%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/di_io.h
	$(COMPILE.c) $(OUTPUT_OPTION) -I $(INCLUDE_DIR) $<

clean:
	rm test
	rm *.o

.PHONY: test


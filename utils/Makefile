CC = gcc
OBJS = utils.o utils_test.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lssl -lcrypto
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

test: $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o test

utils.o: utils.c utils.h
	$(CC) $(FLAGS) -c utils.c

.PHONY: clean
clean:
	@echo "$(RED)Deleted files:$(RESET) test $(OBJS)"

	rm -f test $(OBJS)
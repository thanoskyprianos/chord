CC = gcc
OBJS = list.o list_test.o ../hashtable/hashtable.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto -lssl
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

test: $(OBJS)
	$(MAKE) -C ../hashtable hashtable.o
	$(CC) $(OBJS) $(FLAGS) -o test

list.o: list.c list.h
	$(CC) $(FLAGS) -c list.c

.PHONY: clean
clean:
	@echo "$(RED)Deleted files:$(RESET) test $(OBJS)"

	rm -f test $(OBJS)
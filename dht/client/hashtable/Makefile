CC = gcc
OBJS = hashtable_test.o hashtable.o ../list/list.o ../../../utils/utils.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto -lssl
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

test: $(OBJS)
	$(MAKE) -C ../list list.o
	$(MAKE) -C ../../../utils utils.o
	$(CC) $(OBJS) $(FLAGS) -o test

hashtable.o: hashtable.c hashtable.h
	$(CC) $(FLAGS) -c hashtable.c

.PHONY: clean
clean:
	@echo "$(RED)Deleted files:$(RESET) test $(OBJS)"

	rm -f test $(OBJS)
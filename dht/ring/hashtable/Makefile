CC = gcc
OBJS = hashtable.o hashtable_test.o ../../node/node.o ../../../utils/utils.o ../list/list.o ../../client/hashtable/hashtable.o ../../client/list/list.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto -lssl
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

test: $(OBJS)
	$(MAKE) hashtable.o
	$(CC) $(OBJS) $(FLAGS) -o test

hashtable.o: hashtable.c hashtable.h
	$(MAKE) -C ../list list.o
	$(MAKE) -C ../../client/hashtable hashtable.o
	$(MAKE) -C ../../client/list list.o
	$(MAKE) -C ../../node node.o
	$(MAKE) -C ../../../utils utils.o
	$(CC) $(FLAGS) -c hashtable.c

.PHONY: clean
clean:
	@echo "$(RED)Deleted files:$(RESET) test $(OBJS)"

	rm -f test $(OBJS)
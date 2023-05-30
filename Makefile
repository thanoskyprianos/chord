CC 	 = gcc
OBJS = main.o ./list/list.o ./hashtable/hashtable.o ./dht/dht.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

main: $(OBJS)
	$(MAKE) -C ./list list.o
	$(MAKE) -C ./hashtable hashtable.o
	$(MAKE) -C ./dht dht.o
	$(CC) $(FLAGS) $(OBJS) -o main

test:
	$(MAKE) -C ./list test
	$(MAKE) -C ./hashtable test
	# $(MAKE) -C ./dht test

	@echo "\n$(CYAN)List tests:$(RESET)"
	./list/test

	@echo "\n$(CYAN)Hashtable tests:$(RESET)"
	./hashtable/test

	# @echo "\n$(CYAN)DHT tests:$(RESET)"
	# ./dht/test

	@echo # newline
	$(MAKE) clean

.PHONY: clean
clean:

	@echo "$(RED)Deleted files:$(RESET) main $(OBJS)"

	rm -f main $(OBJS)
	$(MAKE) -C ./list clean
	$(MAKE) -C ./hashtable clean
	# $(MAKE) -C ./dht clean
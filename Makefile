CC 	 = gcc
OBJS = main.o ./dht/client/list/list.o ./dht/client/hashtable/hashtable.o ./dht/dht.o ./utils/utils.o
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

main: $(OBJS)
	$(MAKE) -C ./dht/client/list list.o
	$(MAKE) -C ./dht/client/hashtable hashtable.o
	$(MAKE) -C ./dht dht.o
	$(MAKE) -C ./utils utils.o
	$(CC) $(FLAGS) $(OBJS) -o main

test:
	$(MAKE) -C ./dht/client/list test
	$(MAKE) -C ./dht/client/hashtable test
	$(MAKE) -C ./utils test

	@echo "\n$(CYAN)List tests (Client):$(RESET)"
	./dht/client/list/test

	@echo "\n$(CYAN)Hashtable tests (Client):$(RESET)"
	./dht/client/hashtable/test

	# @echo "\n$(CYAN)DHT tests:$(RESET)"
	# ./dht/test

	@echo "\n$(CYAN)Utils tests:$(RESET)"
	./utils/test

	@echo # newline
	$(MAKE) clean

.PHONY: clean
clean:

	@echo "$(RED)Deleted files:$(RESET) main $(OBJS)"

	rm -f main $(OBJS)
	$(MAKE) -C ./dht/client/list clean
	$(MAKE) -C ./dht/client/hashtable clean
	# $(MAKE) -C ./dht clean
	$(MAKE) -C ./utils clean
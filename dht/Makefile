CC = gcc
FLAGS = -g3 -Wall -Werror -Wextra -pedantic -lcrypto -lssl
MAKE = make -s

CYAN = \e[1;96m
RED = \e[1;91m
RESET = \e[0m

ifndef PRINT
.SILENT:
endif

dht.o: dht.c dht.h
	$(CC) $(FLAGS) -c dht.c

.PHONY: clean
clean:
	@echo "$(RED)Deleted files:$(RESET) dht.o"

	rm -f dht.o
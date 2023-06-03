#include <stdio.h>
#include <stdbool.h>

#include "dht/dht.h"
#include "dht/ring/hashtable/hashtable.h"

extern hash_table_ring ring;       // chord network
extern keyType ips[MAXNODENUMBER]; // ips of nodes

size_t main_menu(void) {
  clear_screen();

  printf(CYAN"Main menu\n"RESET);
  printf("0. Exit\n");
  printf("1. Client selection\n");

  size_t choice;
  printf("Your choice: ");
  while(scanf("%zu", &choice) != 1 || (choice != 0 && choice != 1)) {
    clear_previous_input();
    
    printf("\033[1A\033[2K"); // move cursor up 1 line and clear
    printf(RED"Invalid choice. "RESET"Try again: ");
  }

  return choice;
}

nodeType client_select_menu(void) {
  clear_screen();
  size_t index = 0;

  while(true) {
    clear_screen();
    printf(CYAN"Server selection (Page %zu/%d)\n"RESET, index / CLIENTS_PER_SCREEN + 1, MAXNODENUMBER / CLIENTS_PER_SCREEN);
    for(size_t i = 0; i < CLIENTS_PER_SCREEN; i++) {
      printf("%-2zu. %s\n", i + 1, ips[index]);
      index = (index + 1) % MAXNODENUMBER;
    }

    printf(CYAN"\nChoices\n"RESET);
    printf("0.    Back\n");
    printf("1-%d. Select server\n", CLIENTS_PER_SCREEN);
    printf("%d.   Next page\n", CLIENTS_PER_SCREEN + 1);

    size_t choice;
    printf("Your choice: ");
    while(scanf("%zu", &choice) != 1 || choice < 0 || choice > CLIENTS_PER_SCREEN + 1) {
      clear_previous_input();
      
      printf("\033[1A\033[2K"); // move cursor up 1 line and clear
      printf(RED"Invalid choice. "RESET"Try again: ");
    }

    if(choice == 0)
      return NULL;
    else if(choice == CLIENTS_PER_SCREEN + 1)
      continue;
    else
      return hashtable_get_ring(ips[index - CLIENTS_PER_SCREEN + choice - 1], ring);
  }
}

size_t client_options_menu(nodeType client) {
  clear_screen();

  printf(CYAN"Client options(%s)\n"RESET, node_id(client));
  printf("0. Back\n");
  printf("1. Insert\n");
  printf("2. Lookup\n");
  printf("3. Smart lookup\n");

  size_t choice;
  printf("Your choice: ");
  while(scanf("%zu", &choice) != 1 || choice < 0 || choice > 3) {
    clear_previous_input();
    
    printf("\033[1A\033[2K"); // move cursor up 1 line and clear
    printf(RED"Invalid choice. "RESET"Try again: ");
  }

  return choice;
}

void insert_menu(nodeType client) {
  clear_screen();

  printf(CYAN"Insert(%s)\n"RESET, node_id(client));
  
  char buffer[1024]; clear_previous_input();
  
  printf("Give key: "); fgets(buffer, 1024, stdin);
  buffer[strlen(buffer) - 1] = '\0';

  valueType value;
  printf("Give value: "); scanf("%d", &value);

  insert(client, buffer, value);

  printf("\033[2A\033[2K"); // move cursor up 2 lines and clear
  clear_previous_input();
  printf(GREEN"Inserted (%s, %d) successfully\n"RESET, buffer, value);
  wait_for_enter();
}

void lookup_menu(nodeType client, valueType (*lookup)(nodeType, keyType)) {
  clear_screen();

  printf(CYAN"Lookup(%s)\n"RESET, node_id(client));
  
  char buffer[1024]; clear_previous_input();
  
  printf("Give key: "); fgets(buffer, 1024, stdin);
  buffer[strlen(buffer) - 1] = '\0';

  printf("\033[1A\033[2K"); // move cursor up 1 line and clear

  valueType value = lookup(client, buffer);
  if(value == EMPTY)
    printf(RED"%s not found\n"RESET, buffer);
  else 
    printf(GREEN"%s found! Value: %d\n"RESET, buffer, value);

  wait_for_enter();
}

int main(void) {
  initialize();

  bool run = true;
  while (run) {
    nodeType client = NULL;

    size_t choice = main_menu();
    switch (choice) {
      case 0: run = false; continue;
      case 1: 
        client = client_select_menu();
        if(client == NULL) continue;
        break;
    }

    bool proccessing = true;
    while(proccessing) {
      size_t choice = client_options_menu(client);
      switch (choice) {
        case 0: proccessing = false; break;
        case 1: insert_menu(client); break;
        case 2: lookup_menu(client, lookup); break;
        case 3: lookup_menu(client, smartLookup); break;
      }
    }
  }

  terminate();

  printf("\n");
  return 0;
}
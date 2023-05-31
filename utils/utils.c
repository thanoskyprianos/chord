#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#include "utils.h"

void string_copy(char **dest, char *src) {
  int len = strlen(src);
  (*dest) = malloc((len + 1) * sizeof(char));
  memcpy((*dest), src, len + 1);
}

char *random_ip(void) {
  srand(time(NULL));

  char ip[16]; // xxx.xxx.xxx.xxx + '\0'
  char temp[4];
  
  ip[0] = '\0'; // needed for strcat
  
  for(int i = 0; i < 4; i++) {
    size_t num = rand() % 256;

    sprintf(temp, "%ld", num);
    strcat(ip, temp);

    if(i != 3)
      strcat(ip, ".");
  }

  char *final;
  string_copy(&final, ip);
  return final;  
}

size_t hash(keyType key) {
  unsigned char hash_array[SHA_DIGEST_LENGTH];
  SHA1((unsigned char *)key, strlen(key), hash_array);

  return (size_t)hash_array[0]; // first 8 bits of SHA1 key
}
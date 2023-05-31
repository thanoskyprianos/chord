#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#include "utils.h"

void string_copy(char **dest, char *src) {
  int len = strlen(src);
  (*dest) = malloc((len + 1) * sizeof(char));
  memcpy((*dest), src, len + 1);
}

keyType random_ip(void) {

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
  return (keyType)final;
}

size_t hash(keyType key) {
  unsigned char hash_array[SHA_DIGEST_LENGTH];
  SHA1((unsigned char *)key, strlen(key), hash_array);

  return (size_t)hash_array[0]; // first 8 bits of SHA1 key
}

bool is_prime(size_t n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;
   
    for (size_t i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
           return false;
   
    return true;
}


size_t next_prime(size_t n) {
  if (n <= 1)
    return 2;

  size_t prime = n;
  while (!is_prime(prime++));

  return prime - 1;
}
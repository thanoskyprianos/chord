#include "../acutest/acutest.h"

#include "utils.h"

void test_string_copy(void) {
  char *src = "Hello World!";
  char *dest;

  string_copy(&dest, src);

  TEST_CHECK(strcmp(src, dest) == 0);

  free(dest);
}

void test_random_ip(void) {
  char *ip = random_ip();

  size_t length = strlen(ip);
  TEST_CHECK(length >= 7 && length <= 15);

  free(ip);
}

void test_hash(void) {
  size_t hash1 = hash("John");

  TEST_CHECK(hash1 >= 0 && hash1 <= 255);
}

void test_is_prime(void) {
  TEST_CHECK(is_prime(2));
  TEST_CHECK(is_prime(3));
  TEST_CHECK(!is_prime(4));
  TEST_CHECK(is_prime(11));
  TEST_CHECK(!is_prime(12));
}

void test_next_prime(void) {
  TEST_CHECK(next_prime(10) == 11);
  TEST_CHECK(next_prime(11) == 11); // 11 is already prime
  TEST_CHECK(next_prime(12) == 13);
  TEST_CHECK(next_prime(13) == 13); // 13 is already prime
  TEST_CHECK(next_prime(15) == 17);
}

TEST_LIST = {
  {"string_copy", test_string_copy},
  {"random_ip", test_random_ip},
  {"hash", test_hash},
  {"is_prime", test_is_prime},
  {"next_prime", test_next_prime},
  {NULL, NULL}
};
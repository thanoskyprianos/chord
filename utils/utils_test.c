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

TEST_LIST = {
  {"string_copy", test_string_copy},
  {"random_ip", test_random_ip},
  {NULL, NULL}
};
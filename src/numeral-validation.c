#include "src/numeral-validation.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

static bool is_empty_string(const char *string);

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  if (is_empty_string(string)) {
    return false;
  }

  regex_t regex;

  char pattern[] = "^C?(L?X{0,3}|X[LC])(V?I{0,3}|I[VX])$";

  if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}

static bool is_empty_string(const char *string) {
  assert(string != NULL);
  return strcmp("", string) == 0;
}

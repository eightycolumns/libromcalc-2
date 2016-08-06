#include "src/numeral-validation.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <stddef.h>

bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  regex_t regex;

  char pattern[] = "^X?(V?I{0,3}|I[VX])$";

  if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}

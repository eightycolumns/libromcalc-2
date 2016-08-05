#include "src/romcalc.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

static bool is_roman_numeral(const char *string);
static int roman_to_arabic(const char *roman);
static char *arabic_to_roman(char *roman, int arabic);

int add(char *sum, const char *augend, const char *addend) {
  if (sum == NULL || augend == NULL || addend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  if (!is_roman_numeral(augend) || !is_roman_numeral(addend)) {
    return ROMCALC_INVALID_OPERAND_ERROR;
  }

  int result = roman_to_arabic(augend) + roman_to_arabic(addend);

  arabic_to_roman(sum, result);

  return ROMCALC_SUCCESS;
}

int subtract(char *difference, const char *minuend, const char *subtrahend) {
  if (difference == NULL || minuend == NULL || subtrahend == NULL) {
    return ROMCALC_NULL_POINTER_ERROR;
  }

  return ROMCALC_SUCCESS;
}

static bool is_roman_numeral(const char *string) {
  assert(string != NULL);

  regex_t regex;

  char pattern[] = "^(V?I{0,3}|IV)$";

  if (regcomp(&regex, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
    return false;
  }

  bool result = (regexec(&regex, string, 0, NULL, 0) == 0);

  regfree(&regex);

  return result;
}

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  if (strcmp("I", roman) == 0) {
    arabic = 1;
  } else if (strcmp("II", roman) == 0) {
    arabic = 2;
  } else if (strcmp("III", roman) == 0) {
    arabic = 3;
  } else if (strcmp("IV", roman) == 0) {
    arabic = 4;
  }

  return arabic;
}

static char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  if (arabic == 2) {
    strcpy(roman, "II");
  } else if (arabic == 3) {
    strcpy(roman, "III");
  } else if (arabic == 4) {
    strcpy(roman, "IV");
  } else if (arabic == 5) {
    strcpy(roman, "V");
  }

  return roman;
}

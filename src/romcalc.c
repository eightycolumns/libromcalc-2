#include "src/romcalc.h"

#include <assert.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} Numeral;

static Numeral numerals[] = {
  {"I", 1},
  {"II", 2},
  {"III", 3},
  {"IV", 4},
  {"V", 5},
  {"IX", 9},
  {"X", 10}
};

static size_t numeral_count = sizeof numerals / sizeof numerals[0];

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

  int result = roman_to_arabic(minuend) - roman_to_arabic(subtrahend);

  arabic_to_roman(difference, result);

  return ROMCALC_SUCCESS;
}

static bool is_roman_numeral(const char *string) {
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

static int roman_to_arabic(const char *roman) {
  assert(roman != NULL);

  int arabic = 0;

  for (size_t i = 0; i < numeral_count; i += 1) {
    if (strcmp(roman, numerals[i].key) == 0) {
      arabic = numerals[i].value;
    }
  }

  return arabic;
}

static char *arabic_to_roman(char *roman, int arabic) {
  assert(roman != NULL);

  for (size_t i = 0; i < numeral_count; i += 1) {
    if (arabic == numerals[i].value) {
      strcpy(roman, numerals[i].key);
    }
  }

  return roman;
}

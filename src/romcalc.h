#ifndef ROMCALC_H
#define ROMCALC_H

enum {
  ROMCALC_SUCCESS,
  ROMCALC_NULL_POINTER_ERROR
};

int add(char *sum, const char *augend, const char *addend);

#endif

#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"
#include "test/error-handling.h"
#include "test/addition.h"
#include "test/subtraction.h"

static Suite *operations(void);

int main(void) {
  SRunner *srunner = srunner_create(error_handling());
  srunner_add_suite(srunner, operations());

  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

static Suite *operations(void) {
  Suite *operations = suite_create("Operations");
  suite_add_tcase(operations, addition());
  suite_add_tcase(operations, subtraction());

  return operations;
}

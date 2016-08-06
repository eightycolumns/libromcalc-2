#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"
#include "test/success.h"
#include "test/null-pointer-error.h"
#include "test/invalid-operand-error.h"
#include "test/addition.h"
#include "test/subtraction.h"

static Suite *error_handling(void);

int main(void) {
  Suite *operations = suite_create("Operations");
  suite_add_tcase(operations, addition());
  suite_add_tcase(operations, subtraction());

  SRunner *srunner = srunner_create(error_handling());
  srunner_add_suite(srunner, operations);

  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

static Suite *error_handling(void) {
  Suite *error_handling = suite_create("Error Handling");
  suite_add_tcase(error_handling, success());
  suite_add_tcase(error_handling, null_pointer_error());
  suite_add_tcase(error_handling, invalid_operand_error());

  return error_handling;
}

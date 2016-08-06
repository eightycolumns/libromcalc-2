#include <stdlib.h>

#include <check.h>

#include "src/romcalc.h"
#include "test/success.h"
#include "test/null-pointer-error.h"
#include "test/invalid-operand-error.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(I_plus_I_is_II) {
  char expected[] = "II";
  add(actual, "I", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(II_plus_I_is_III) {
  char expected[] = "III";
  add(actual, "II", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(III_plus_I_is_IV) {
  char expected[] = "IV";
  add(actual, "III", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IV_plus_I_is_V) {
  char expected[] = "V";
  add(actual, "IV", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(V_plus_IV_is_IX) {
  char expected[] = "IX";
  add(actual, "V", "IV");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IX_plus_I_is_X) {
  char expected[] = "X";
  add(actual, "IX", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(X_minus_I_is_IX) {
  char expected[] = "IX";
  subtract(actual, "X", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IX_minus_IV_is_V) {
  char expected[] = "V";
  subtract(actual, "IX", "IV");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(V_minus_I_is_IV) {
  char expected[] = "IV";
  subtract(actual, "V", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(IV_minus_II_is_II) {
  char expected[] = "II";
  subtract(actual, "IV", "II");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(II_minus_I_is_I) {
  char expected[] = "I";
  subtract(actual, "II", "I");
  ck_assert_str_eq(expected, actual);
} END_TEST

static TCase *addition(void);
static TCase *subtraction(void);

int main(void) {
  Suite *error_handling = suite_create("Error Handling");
  suite_add_tcase(error_handling, success());
  suite_add_tcase(error_handling, null_pointer_error());
  suite_add_tcase(error_handling, invalid_operand_error());

  Suite *operations = suite_create("Operations");
  suite_add_tcase(operations, addition());
  suite_add_tcase(operations, subtraction());

  SRunner *srunner = srunner_create(error_handling);
  srunner_add_suite(srunner, operations);

  srunner_run_all(srunner, CK_ENV);
  int ntests_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (ntests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

static TCase *addition(void) {
  TCase *addition = tcase_create("Addition");
  tcase_add_test(addition, I_plus_I_is_II);
  tcase_add_test(addition, II_plus_I_is_III);
  tcase_add_test(addition, III_plus_I_is_IV);
  tcase_add_test(addition, IV_plus_I_is_V);
  tcase_add_test(addition, V_plus_IV_is_IX);
  tcase_add_test(addition, IX_plus_I_is_X);

  return addition;
}

static TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");
  tcase_add_test(subtraction, X_minus_I_is_IX);
  tcase_add_test(subtraction, IX_minus_IV_is_V);
  tcase_add_test(subtraction, V_minus_I_is_IV);
  tcase_add_test(subtraction, IV_minus_II_is_II);
  tcase_add_test(subtraction, II_minus_I_is_I);

  return subtraction;
}

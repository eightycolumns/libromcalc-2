#include "test/addition.h"

#include <check.h>

#include "src/romcalc.h"

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

START_TEST(X_plus_X_is_XX) {
  char expected[] = "XX";
  add(actual, "X", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XX_plus_X_is_XXX) {
  char expected[] = "XXX";
  add(actual, "XX", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

TCase *addition(void) {
  TCase *addition = tcase_create("Addition");
  tcase_add_test(addition, I_plus_I_is_II);
  tcase_add_test(addition, II_plus_I_is_III);
  tcase_add_test(addition, III_plus_I_is_IV);
  tcase_add_test(addition, IV_plus_I_is_V);
  tcase_add_test(addition, V_plus_IV_is_IX);
  tcase_add_test(addition, IX_plus_I_is_X);
  tcase_add_test(addition, X_plus_X_is_XX);
  tcase_add_test(addition, XX_plus_X_is_XXX);

  return addition;
}

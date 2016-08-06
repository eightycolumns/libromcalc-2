#include "test/subtraction.h"

#include <check.h>

#include "src/romcalc.h"

static char actual[ROMCALC_MAX_LENGTH];

START_TEST(M_minus_C_is_CM) {
  char expected[] = "CM";
  subtract(actual, "M", "C");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(CM_minus_CD_is_D) {
  char expected[] = "D";
  subtract(actual, "CM", "CD");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(C_minus_X_is_XC) {
  char expected[] = "XC";
  subtract(actual, "C", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XC_minus_XL_is_L) {
  char expected[] = "L";
  subtract(actual, "XC", "XL");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(L_minus_X_is_XL) {
  char expected[] = "XL";
  subtract(actual, "L", "X");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XL_minus_XX_is_XX) {
  char expected[] = "XX";
  subtract(actual, "XL", "XX");
  ck_assert_str_eq(expected, actual);
} END_TEST

START_TEST(XX_minus_X_is_X) {
  char expected[] = "X";
  subtract(actual, "XX", "X");
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

TCase *subtraction(void) {
  TCase *subtraction = tcase_create("Subtraction");
  tcase_add_test(subtraction, M_minus_C_is_CM);
  tcase_add_test(subtraction, CM_minus_CD_is_D);
  tcase_add_test(subtraction, C_minus_X_is_XC);
  tcase_add_test(subtraction, XC_minus_XL_is_L);
  tcase_add_test(subtraction, L_minus_X_is_XL);
  tcase_add_test(subtraction, XL_minus_XX_is_XX);
  tcase_add_test(subtraction, XX_minus_X_is_X);
  tcase_add_test(subtraction, X_minus_I_is_IX);
  tcase_add_test(subtraction, IX_minus_IV_is_V);
  tcase_add_test(subtraction, V_minus_I_is_IV);
  tcase_add_test(subtraction, IV_minus_II_is_II);
  tcase_add_test(subtraction, II_minus_I_is_I);

  return subtraction;
}

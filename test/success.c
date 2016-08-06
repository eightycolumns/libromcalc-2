#include "test/success.h"

#include <check.h>

#include "src/romcalc.h"

static char sum[ROMCALC_MAX_LENGTH];

START_TEST(I_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "I", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(II_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "II", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(III_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "III", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(IV_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "IV", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(V_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "V", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(IX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "IX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(X_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "X", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XXX_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XXX", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XL_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XL", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(L_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "L", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(XC_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "XC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(C_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "C", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CC_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CCC_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CCC", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

START_TEST(CD_is_a_valid_operand) {
  int expected = ROMCALC_SUCCESS;
  int actual = add(sum, "CD", "I");
  ck_assert_int_eq(expected, actual);
} END_TEST

TCase *success(void) {
  TCase *success = tcase_create("Success");
  tcase_add_test(success, I_is_a_valid_operand);
  tcase_add_test(success, II_is_a_valid_operand);
  tcase_add_test(success, III_is_a_valid_operand);
  tcase_add_test(success, IV_is_a_valid_operand);
  tcase_add_test(success, V_is_a_valid_operand);
  tcase_add_test(success, IX_is_a_valid_operand);
  tcase_add_test(success, X_is_a_valid_operand);
  tcase_add_test(success, XX_is_a_valid_operand);
  tcase_add_test(success, XXX_is_a_valid_operand);
  tcase_add_test(success, XL_is_a_valid_operand);
  tcase_add_test(success, L_is_a_valid_operand);
  tcase_add_test(success, XC_is_a_valid_operand);
  tcase_add_test(success, C_is_a_valid_operand);
  tcase_add_test(success, CC_is_a_valid_operand);
  tcase_add_test(success, CCC_is_a_valid_operand);
  tcase_add_test(success, CD_is_a_valid_operand);

  return success;
}

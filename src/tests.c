#include <check.h>

#include "s21_matrix.h"

/* CREATE */
START_TEST(create_1) {
  matrix_t A;
  int rows = 0;
  int columns = 1;
  int res = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_2) {
  int rows = 10;
  int columns = 10;
  int res = s21_create_matrix(rows, columns, NULL);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

/* EQUAL */
START_TEST(eq_2) {
  matrix_t m = {0};
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows1, cols1, &mtx);
  ck_assert_int_eq(s21_eq_matrix(&m, &mtx), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(eq_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
}

START_TEST(eq_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_12) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_13) {
  int res = s21_eq_matrix(NULL, NULL);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(eq_14) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  A.rows = 0;
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  A.rows = 10;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_15) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 9, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_16) {
  matrix_t A;
  matrix_t B;
  double nums[4] = {123.456, 2, 3, 4};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(nums, &A);
  s21_set(nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_17) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1.2345678, 2, 3, 4};
  double B_nums[4] = {1.2345678, 2, 3, 4};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_18) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1.23456789, 2, 3, 4};
  double B_nums[4] = {1.23456789, 2, 3, 4};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_19) {
  matrix_t A;
  matrix_t B;
  double A_nums[4] = {1.2345678, 2, 3, 4};
  double B_nums[4] = {1.2345677, 2, 3, 4};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/* SUMM */

START_TEST(sum_0) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 38.12389;
  B.matrix[0][0] = -129.4910;
  C.matrix[0][0] = -91.36711;
  int res = s21_sum_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double B_nums[4] = {109428035910.10189, -19872409.1489, 3, 140912.5};
  double result_nums[4] = {109428157149.21489, -19870008.02498, -348898.2,
                           2529926.5};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_sum_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                      912039.12389,  129034.23400, 0,         1203,
                      9000000.123};
  double B_nums[9] = {
      109428035910.1024189, -19872409.1489, 3, 140912.5, 0, 12930124, 1942.3489,
      102.234891,           10230912.1};
  double result_nums[9] = {
      109428157149.2244319, -19870008.02498, -348898.2, 2529926.5,
      912039.12389,         13059158.234,    1942.3489, 1305.234891,
      19230912.223};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_sum_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sum_4) {
  matrix_t A;
  int res = s21_sum_matrix(NULL, &A, &A);
  ck_assert_int_eq(res, 1);
}

START_TEST(sum_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);
  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  A.rows = 0;
  int res = s21_sum_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_7) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double B_nums[6] = {2, 3, 4, 5, 6, 7};
  double result_nums[6] = {3, 5, 7, 9, 11, 13};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_sum_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}

/* REMOVE */
START_TEST(remove_1) { s21_remove_matrix(NULL); }
END_TEST

START_TEST(remove_2) {
  matrix_t A;
  s21_create_matrix(10, 10, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_int_eq(A.columns, 0);
}
END_TEST

/* SUB */
START_TEST(sub_1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 38.12389;
  B.matrix[0][0] = -129.4910;
  C.matrix[0][0] = 167.61489;
  int res = s21_sub_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sub_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double B_nums[4] = {109910.10189, -19872409.1489, 3, 140912.5};
  double result_nums[4] = {11329.01111, 19874810.27282, -348904.2, 2248101.5};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_sub_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sub_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                      912039.12389,  129034.23400, 0,         1203,
                      9000000.123};
  double B_nums[9] = {
      109428035910.1024189, -19872409.1489, 3, 140912.5, 0, 12930124, 1942.3489,
      102.234891,           10230912.1};
  double result_nums[9] = {
      -109427914670.9804059, 19874810.27282, -348904.2,  2248101.5,
      912039.12389,          -12801089.766,  -1942.3489, 1100.765109,
      -1230911.977};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_sub_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(sub_4) {
  matrix_t A;
  int res = s21_sub_matrix(NULL, &A, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(sub_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 1, &B);
  int res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  A.rows = 0;
  int res = s21_sub_matrix(&A, &B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_7) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double B_nums[6] = {2, 3, 4, 5, 6, 7};
  double result_nums[6] = {-1, -1, -1, -1, -1, -1};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(3, 2, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int result = s21_sub_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

/* MULTI NUM */
START_TEST(multi_num_1) {
  matrix_t A;
  int res = s21_mult_number(NULL, 10, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(multi_num_2) {
  matrix_t A;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_mult_number(&A, 10, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(multi_num_3) {
  matrix_t A;
  double number = 3.12890;
  matrix_t B;
  matrix_t C;
  double A_nums[4] = {121239.113, 2401.12392, -348901.2, 2389014};
  double result_nums[4] = {379345.0606657, 7512.876633288, -1091676.96468,
                           7474985.9046};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_set(A_nums, &A);
  s21_set(result_nums, &B);
  int result = s21_mult_number(&A, number, &C);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(multi_num_4) {
  matrix_t A;
  double number = 3901.904;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {121239.122013, 2401.12392,   -348901.2, 2389014,
                      912039.12389,  129034.23400, 0,         1203,
                      9000000.123};
  double result_nums[9] = {473063415.139012752,
                           9368955.02794368,
                           -1361378987.8848,
                           9321703282.656,
                           3558689105.66288656,
                           503479193.781536,
                           0,
                           4693990.512,
                           35117136479.934192};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_set(A_nums, &A);
  s21_set(result_nums, &B);
  int res = s21_mult_number(&A, number, &C);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

/* MULTI MAT */
START_TEST(multi_mat_1) {
  matrix_t A;
  int result = s21_mult_matrix(NULL, &A, &A);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(multi_mat_2) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(10, 10, &B);
  A.rows = 0;
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(multi_mat_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(multi_mat_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[6] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
  double B_nums[6] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0};
  double result_nums[9] = {92.4, 117.6, 205.8, 268.8};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 2, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_mult_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(multi_mat_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[9] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2, 8.4, 9.6, 10.8};
  double B_nums[9] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0, 24.5, 28.0, 31.5};
  double result_nums[9] = {126,   151.2, 176.4, 277.2, 340.2,
                           403.2, 428.4, 529.2, 630};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_mult_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

START_TEST(multi_mat_6) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  matrix_t D;
  double A_nums[6] = {1.2, 2.4, 3.6, 4.8, 6.0, 7.2};
  double B_nums[6] = {3.5, 7.0, 10.5, 14.0, 17.5, 21.0};
  double result_nums[9] = {37.8,  50.4,  63,  79.8, 109.2,
                           138.6, 121.8, 168, 214.2};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(B_nums, &B);
  s21_set(result_nums, &C);
  int res = s21_mult_matrix(&A, &B, &D);
  ck_assert_int_eq(s21_eq_matrix(&C, &D), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&D);
}
END_TEST

/* TRANSPOSE */
START_TEST(transpose_1) {
  matrix_t A;
  int res = s21_transpose(NULL, &A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double result_nums[6] = {1, 4, 2, 5, 3, 6};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double result_nums[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[6] = {1, 2, 3, 4, 5, 6};
  double result_nums[6] = {1, 3, 5, 2, 4, 6};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_transpose(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&C, &B), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

/* DETERMINANT */
START_TEST(deter_1) {
  int result = s21_determinant(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(deter_2) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_3) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 9, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_4) {
  matrix_t A;
  double det;
  double det_true = 984.1238;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 984.1238;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_6) {
  matrix_t A;
  double det;
  double det_true = -40;
  double A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  s21_create_matrix(3, 3, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_7) {
  matrix_t A;
  double det;
  double det_true = -1369800;
  double A_nums[25] = {1,  2,  3,   4, 5,  6,  7,  8,  9,  10, 11, 12, 49,
                       14, 15, 161, 7, 18, 19, 20, 64, 48, 1,  2,  3};
  s21_create_matrix(5, 5, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_8) {
  matrix_t A;
  double det;
  double det_true = 17187;
  double A_nums[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+07);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(deter_9) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(deter_10) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(deter_11) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(deter_12) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(deter_13) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(deter_14) {
  const int size = 1;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e+07);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

/* COMPLEMENTS */
START_TEST(complements_1) {
  int result = s21_calc_complements(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(complements_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  double result_nums[9] = {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(complements_6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(complements_7) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(complements_8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(complements_9) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 && code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(complements_11) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(3, 3, &first);
  s21_create_matrix(3, 3, &desiredResult);

  first.matrix[0][0] = 1;
  first.matrix[0][1] = 2;
  first.matrix[0][2] = 3;

  first.matrix[1][0] = 0;
  first.matrix[1][1] = 4;
  first.matrix[1][2] = 2;

  first.matrix[2][0] = 5;
  first.matrix[2][1] = 2;
  first.matrix[2][2] = 1;

  desiredResult.matrix[0][0] = 0;
  desiredResult.matrix[0][1] = 10;
  desiredResult.matrix[0][2] = -20;

  desiredResult.matrix[1][0] = 4;
  desiredResult.matrix[1][1] = -14;
  desiredResult.matrix[1][2] = 8;

  desiredResult.matrix[2][0] = -8;
  desiredResult.matrix[2][1] = -2;
  desiredResult.matrix[2][2] = 4;

  int myReturnValue = s21_calc_complements(&first, &myResult);
  int desiredReturnValue = OK;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(complements_12) {
  matrix_t first = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 3, &first);

  int myReturnValue = s21_calc_complements(&first, &myResult);
  int desiredReturnValue = CALCULATION_ERROR;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);

  s21_remove_matrix(&first);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(complements_13) {
  matrix_t myResult = {0};
  int myReturnValue = s21_calc_complements(NULL, &myResult);
  int desiredReturnValue = INCORRECT_MATRIX;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
}
END_TEST

START_TEST(complements_14) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 1, &first);
  s21_create_matrix(1, 1, &desiredResult);

  first.matrix[0][0] = 0;

  desiredResult.matrix[0][0] = 0;

  int myReturnValue = s21_calc_complements(&first, &myResult);
  int desiredReturnValue = OK;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

/* INVERSE */
START_TEST(inverse_1) {
  int res = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 42.12849;
  C.matrix[0][0] = 1 / 42.12849;
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_double_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double A_nums[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double result_nums[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  s21_set(A_nums, &A);
  s21_set(result_nums, &C);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_double_eq(s21_eq_matrix(&B, &C), 1);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t A;
  matrix_t B;
  double A_nums[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                       14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  s21_create_matrix(5, 5, &A);
  s21_set(A_nums, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_7) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(inverse_9) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_10) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_11) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_12) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_13) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(3, 3, &first);
  s21_create_matrix(3, 3, &desiredResult);

  first.matrix[0][0] = 2;
  first.matrix[0][1] = 5;
  first.matrix[0][2] = 7;

  first.matrix[1][0] = 6;
  first.matrix[1][1] = 3;
  first.matrix[1][2] = 4;

  first.matrix[2][0] = 5;
  first.matrix[2][1] = -2;
  first.matrix[2][2] = -3;

  desiredResult.matrix[0][0] = 1;
  desiredResult.matrix[0][1] = -1;
  desiredResult.matrix[0][2] = 1;

  desiredResult.matrix[1][0] = -38;
  desiredResult.matrix[1][1] = 41;
  desiredResult.matrix[1][2] = -34;

  desiredResult.matrix[2][0] = 27;
  desiredResult.matrix[2][1] = -29;
  desiredResult.matrix[2][2] = 24;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = OK;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_14) {
  matrix_t first = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 3, &first);

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = CALCULATION_ERROR;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);

  s21_remove_matrix(&first);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_15) {
  matrix_t myResult = {0};
  int myReturnValue = s21_inverse_matrix(NULL, &myResult);
  int desiredReturnValue = INCORRECT_MATRIX;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
}
END_TEST

START_TEST(inverse_16) {
  matrix_t first = {0};
  matrix_t desiredResult = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 1, &first);
  s21_create_matrix(1, 1, &desiredResult);

  first.matrix[0][0] = 4;

  desiredResult.matrix[0][0] = 0.25;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = OK;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);
  ck_assert_int_eq(s21_eq_matrix(&myResult, &desiredResult), SUCCESS);

  s21_remove_matrix(&first);
  s21_remove_matrix(&desiredResult);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_17) {
  matrix_t first = {0};
  matrix_t myResult = {0};
  s21_create_matrix(1, 1, &first);

  first.matrix[0][0] = 0;

  int myReturnValue = s21_inverse_matrix(&first, &myResult);
  int desiredReturnValue = CALCULATION_ERROR;
  ck_assert_int_eq(myReturnValue, desiredReturnValue);

  s21_remove_matrix(&first);
  s21_remove_matrix(&myResult);
}
END_TEST

START_TEST(inverse_18) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (codec1 && codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(inverse_19) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(complements_15) {
  int rows = 3, cols = 3;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  double fill_matrix_2[9] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  s21_set(fill_matrix_2, &m1);

  int res = s21_calc_complements(&m1, &m2);
  ck_assert_int_eq(res, 0);

  ck_assert_double_eq(m2.matrix[0][0], 0);
  ck_assert_double_eq(m2.matrix[0][1], 10);
  ck_assert_double_eq(m2.matrix[0][2], -20);
  ck_assert_double_eq(m2.matrix[1][0], 4);
  ck_assert_double_eq(m2.matrix[1][1], -14);
  ck_assert_double_eq(m2.matrix[1][2], 8);
  ck_assert_double_eq(m2.matrix[2][0], -8);
  ck_assert_double_eq(m2.matrix[2][1], -2);
  ck_assert_double_eq(m2.matrix[2][2], 4);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST
START_TEST(complements_16) {
  int rows = 3, cols = 3;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  double fill_matrix_2[9] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  s21_set(fill_matrix_2, &m1);

  int res = s21_calc_complements(&m1, &m2);
  ck_assert_int_eq(res, 0);

  ck_assert_double_eq(m2.matrix[0][0], -1);
  ck_assert_double_eq(m2.matrix[0][1], 38);
  ck_assert_double_eq(m2.matrix[0][2], -27);
  ck_assert_double_eq(m2.matrix[1][0], 1);
  ck_assert_double_eq(m2.matrix[1][1], -41);
  ck_assert_double_eq(m2.matrix[1][2], 29);
  ck_assert_double_eq(m2.matrix[2][0], -1);
  ck_assert_double_eq(m2.matrix[2][1], 34);
  ck_assert_double_eq(m2.matrix[2][2], -24);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST
START_TEST(complements_17) {
  matrix_t *m1 = NULL, *m2 = NULL;
  int res = s21_calc_complements(m1, m2);
  ck_assert_int_eq(res, 1);
}
END_TEST
START_TEST(complements_18) {
  int rows = 3, cols = 4;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  int res = s21_calc_complements(&m1, &m2);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}

START_TEST(complements_19) {
  int rows = 5, cols = 5;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  int res = s21_calc_complements(&m1, &m2);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}

Suite *example_create() {
  Suite *suite = suite_create("TESTS");

  TCase *tcase_creat = tcase_create("CREATE");
  tcase_add_test(tcase_creat, create_1);
  tcase_add_test(tcase_creat, create_2);
  suite_add_tcase(suite, tcase_creat);

  TCase *tcase_eql = tcase_create("EQL");
  tcase_add_test(tcase_eql, eq_2);
  tcase_add_test(tcase_eql, eq_3);
  tcase_add_test(tcase_eql, eq_4);
  tcase_add_test(tcase_eql, eq_5);
  tcase_add_test(tcase_eql, eq_6);
  tcase_add_test(tcase_eql, eq_7);
  tcase_add_test(tcase_eql, eq_8);
  tcase_add_test(tcase_eql, eq_9);
  tcase_add_test(tcase_eql, eq_10);
  tcase_add_test(tcase_eql, eq_11);
  tcase_add_test(tcase_eql, eq_12);
  tcase_add_test(tcase_eql, eq_13);
  tcase_add_test(tcase_eql, eq_14);
  tcase_add_test(tcase_eql, eq_15);
  tcase_add_test(tcase_eql, eq_16);
  tcase_add_test(tcase_eql, eq_17);
  tcase_add_test(tcase_eql, eq_18);
  tcase_add_test(tcase_eql, eq_19);

  suite_add_tcase(suite, tcase_eql);

  TCase *tcase_summ = tcase_create("SUMM");
  tcase_add_test(tcase_summ, sum_0);
  tcase_add_test(tcase_summ, sum_1);
  tcase_add_test(tcase_summ, sum_2);
  tcase_add_test(tcase_summ, sum_3);
  tcase_add_test(tcase_summ, sum_4);
  tcase_add_test(tcase_summ, sum_5);
  tcase_add_test(tcase_summ, sum_6);
  tcase_add_test(tcase_summ, sum_7);
  suite_add_tcase(suite, tcase_summ);

  TCase *tcase_remove = tcase_create("REMOVE");
  tcase_add_test(tcase_creat, remove_1);
  tcase_add_test(tcase_creat, remove_2);
  suite_add_tcase(suite, tcase_remove);

  TCase *tcase_sub = tcase_create("SUB");
  tcase_add_test(tcase_sub, sub_1);
  tcase_add_test(tcase_sub, sub_2);
  tcase_add_test(tcase_sub, sub_3);
  tcase_add_test(tcase_sub, sub_4);
  tcase_add_test(tcase_sub, sub_5);
  tcase_add_test(tcase_sub, sub_6);
  tcase_add_test(tcase_sub, sub_7);
  suite_add_tcase(suite, tcase_sub);

  TCase *tcase_mult_number = tcase_create("MULT_NUMBER");
  tcase_add_test(tcase_mult_number, multi_num_1);
  tcase_add_test(tcase_mult_number, multi_num_2);
  tcase_add_test(tcase_mult_number, multi_num_3);
  tcase_add_test(tcase_mult_number, multi_num_4);
  suite_add_tcase(suite, tcase_mult_number);

  TCase *tcase_mult_matrix = tcase_create("MULT_NUMBER");
  tcase_add_test(tcase_mult_matrix, multi_mat_1);
  tcase_add_test(tcase_mult_matrix, multi_mat_2);
  tcase_add_test(tcase_mult_matrix, multi_mat_3);
  tcase_add_test(tcase_mult_matrix, multi_mat_4);
  tcase_add_test(tcase_mult_matrix, multi_mat_5);
  tcase_add_test(tcase_mult_matrix, multi_mat_6);
  suite_add_tcase(suite, tcase_mult_matrix);

  TCase *tcase_trans = tcase_create("MULT_NUMBER");
  tcase_add_test(tcase_trans, transpose_1);
  tcase_add_test(tcase_trans, transpose_2);
  tcase_add_test(tcase_trans, transpose_3);
  tcase_add_test(tcase_trans, transpose_4);
  tcase_add_test(tcase_trans, transpose_5);
  suite_add_tcase(suite, tcase_trans);

  TCase *tcase_deter = tcase_create("DETERMINANT");
  tcase_add_test(tcase_deter, deter_1);
  tcase_add_test(tcase_deter, deter_2);
  tcase_add_test(tcase_deter, deter_3);
  tcase_add_test(tcase_deter, deter_4);
  tcase_add_test(tcase_deter, deter_6);
  tcase_add_test(tcase_deter, deter_7);
  tcase_add_test(tcase_deter, deter_8);
  tcase_add_test(tcase_deter, deter_9);
  tcase_add_test(tcase_deter, deter_10);
  tcase_add_test(tcase_deter, deter_11);
  tcase_add_test(tcase_deter, deter_12);
  tcase_add_test(tcase_deter, deter_13);
  tcase_add_test(tcase_deter, deter_14);
  suite_add_tcase(suite, tcase_deter);

  TCase *tcase_compl = tcase_create("COMPLEMENTS");
  tcase_add_test(tcase_compl, complements_1);
  tcase_add_test(tcase_compl, complements_2);
  tcase_add_test(tcase_compl, complements_3);
  tcase_add_test(tcase_compl, complements_5);
  tcase_add_test(tcase_compl, complements_6);
  tcase_add_test(tcase_compl, complements_7);
  tcase_add_test(tcase_compl, complements_8);
  tcase_add_test(tcase_compl, complements_9);
  tcase_add_test(tcase_compl, complements_11);
  tcase_add_test(tcase_compl, complements_12);
  tcase_add_test(tcase_compl, complements_13);
  tcase_add_test(tcase_compl, complements_14);
  tcase_add_test(tcase_compl, complements_15);
  tcase_add_test(tcase_compl, complements_16);
  tcase_add_test(tcase_compl, complements_17);
  tcase_add_test(tcase_compl, complements_18);
  tcase_add_test(tcase_compl, complements_19);
  suite_add_tcase(suite, tcase_compl);

  TCase *tcase_inverse = tcase_create("INVERSE");
  tcase_add_test(tcase_inverse, inverse_1);
  tcase_add_test(tcase_inverse, inverse_2);
  tcase_add_test(tcase_inverse, inverse_3);
  tcase_add_test(tcase_inverse, inverse_4);
  tcase_add_test(tcase_inverse, inverse_5);
  tcase_add_test(tcase_inverse, inverse_6);
  tcase_add_test(tcase_inverse, inverse_7);
  tcase_add_test(tcase_inverse, inverse_8);
  tcase_add_test(tcase_inverse, inverse_9);
  tcase_add_test(tcase_inverse, inverse_10);
  tcase_add_test(tcase_inverse, inverse_11);
  tcase_add_test(tcase_inverse, inverse_12);
  tcase_add_test(tcase_inverse, inverse_13);
  tcase_add_test(tcase_inverse, inverse_14);
  tcase_add_test(tcase_inverse, inverse_15);
  tcase_add_test(tcase_inverse, inverse_16);
  tcase_add_test(tcase_inverse, inverse_17);
  tcase_add_test(tcase_inverse, inverse_18);
  tcase_add_test(tcase_inverse, inverse_19);
  suite_add_tcase(suite, tcase_inverse);

  return suite;
}

int main() {
  int count;
  Suite *s = example_create();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  count = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
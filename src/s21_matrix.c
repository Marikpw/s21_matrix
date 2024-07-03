#include "s21_matrix.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void s21_set(double *nums, matrix_t *A) {
  int count = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = nums[count];
      count++;
    }
  }
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (rows < 1 || columns < 1 || !result) {
    flag = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix == NULL) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (result->matrix[i] == NULL) {
          flag = INCORRECT_MATRIX;
          break;
        }
        for (int j = 0; j < columns; j++) {
          result->matrix[i][j] = 0.0;
        }
      }
    }
  }

  return flag;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A == NULL || B == NULL || A->rows != B->rows ||
      A->columns != B->columns || A->rows < 1 || A->columns < 1 ||
      B->rows < 1 || B->columns < 1) {
    flag = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabsl(A->matrix[i][j] - B->matrix[i][j]) >= 1e-07) {
          flag = FAILURE;
        }
      }
    }
  }
  return flag;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A == NULL || B == NULL || A->rows < 1 || A->columns < 1 || B->rows < 0 ||
      B->columns < 0) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    flag = CALCULATION_ERROR;
  } else {
    int tryToCreate = s21_create_matrix(A->rows, A->columns, result);

    if (tryToCreate != 0) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A == NULL || B == NULL || A->rows < 1 || A->columns < 1 || B->rows < 0 ||
      B->columns < 0) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    flag = CALCULATION_ERROR;
  } else {
    int tryToCreate = s21_create_matrix(A->rows, A->columns, result);

    if (tryToCreate != 0) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (A == NULL || A->rows < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    int tryToCreate = s21_create_matrix(A->columns, A->rows, result);

    if (tryToCreate != 0) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;

  if (A == NULL || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    int tryToCreate = s21_create_matrix(A->rows, A->columns, result);

    if (tryToCreate != 0) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (A == NULL || B == NULL || A->rows < 1 || A->columns < 1 || B->rows < 1 ||
      B->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    flag = CALCULATION_ERROR;
  } else {
    int tryToCreate = s21_create_matrix(A->rows, B->columns, result);
    if (tryToCreate != 0) {
      flag = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return flag;
}

void s21_get_new_matrix(matrix_t *A, int size, int row, int column,
                        matrix_t *newMatrix) {
  int offsetRow = 0;
  int offsetColumn = 0;

  for (int i = 0; i < size - 1; i++) {
    if (i == row) {
      offsetRow = 1;
    }

    offsetColumn = 0;
    for (int j = 0; j < size - 1; j++) {
      if (j == column) {
        offsetColumn = 1;
      }

      newMatrix->matrix[i][j] = A->matrix[i + offsetRow][j + offsetColumn];
    }
  }
}

double s21_get_determinant(matrix_t *A, int size) {
  int degree = 1;
  double determinant = 0.0;
  if (size == 1) {
    determinant = A->matrix[0][0];
  } else if (size == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    matrix_t newMatrix;
    s21_create_matrix(size - 1, size - 1, &newMatrix);

    for (int i = 0; i < size; i++) {
      s21_get_new_matrix(A, size, 0, i, &newMatrix);
      determinant += degree * (A->matrix[0][i] *
                               s21_get_determinant(&newMatrix, size - 1));
      degree = -degree;
    }
    s21_remove_matrix(&newMatrix);
  }
  return determinant;
}

void initializeMinorMatrix(const matrix_t *original, matrix_t *minorMatrix,
                           int removedRow, int removedColumn) {
  int minorMatrixRow = 0;
  for (int row = 0; row < original->rows; ++row) {
    int minorMatrixColumn = 0;
    for (int column = 0; column < original->columns; ++column) {
      if (row != removedRow && column != removedColumn) {
        minorMatrix->matrix[minorMatrixRow][minorMatrixColumn++] =
            original->matrix[row][column];
      }
    }
    if (row != removedRow) ++minorMatrixRow;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (A == NULL || result == NULL || A->rows < 1 || A->columns < 1 || !result) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    flag = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    int res_creation = s21_create_matrix(A->rows, A->rows, result);
    if (res_creation != INCORRECT_MATRIX) {
      result->matrix[0][0] = 0;
    } else {
      flag = INCORRECT_MATRIX;
    }
  } else {
    int res_creation = s21_create_matrix(A->rows, A->rows, result);
    if (res_creation != INCORRECT_MATRIX) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
          matrix_t newMatrix = {NULL, 0, 0};
          s21_create_matrix(A->rows - 1, A->rows - 1, &newMatrix);
          initializeMinorMatrix(A, &newMatrix, i, j);
          double deter = 0.0;
          deter = s21_get_determinant(&newMatrix, newMatrix.rows);
          result->matrix[i][j] = pow(-1, i + j) * deter;
          s21_remove_matrix(&newMatrix);
        }
      }

    } else {
      flag = INCORRECT_MATRIX;
    }
  }
  return flag;
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;

  if (A == NULL || result == NULL || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    flag = CALCULATION_ERROR;
  } else {
    *result = s21_get_determinant(A, A->rows);
  }
  return flag;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;

  if (A == NULL || result == NULL || A->rows < 1 || A->columns < 1) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != A->rows || s21_get_determinant(A, A->rows) == 0.0) {
    flag = CALCULATION_ERROR;
  } else {
    int try_to_create = s21_create_matrix(A->rows, A->rows, result);
    if (try_to_create != 1) {
      double my_deter = 1.0 / (s21_get_determinant(A, A->rows));

      if (A->rows == 1) {
        result->matrix[0][0] = my_deter;
      } else {
        matrix_t B;
        s21_remove_matrix(result);
        s21_calc_complements(A, result);
        s21_transpose(result, &B);
        s21_remove_matrix(result);
        s21_mult_number(&B, my_deter, result);
        s21_remove_matrix(&B);
      }

    } else {
      flag = INCORRECT_MATRIX;
    }
  }
  return flag;
}

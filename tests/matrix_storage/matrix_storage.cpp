#include <gtest/gtest.h>

extern "C" {
#include "matrix_storage.h"
}

size_t default_cols = 3;
size_t defsult_rows = 2;

int default_rect_matrix[2][3] = {{0,1, 2},
                                 {3, 4, 5} };
int empty_rect_matrix;
char string_rect_matrix[] = "0 1 2\n3 4 5";

TEST(matrix_storage, matrix_constructor) {
    Matrix *expected_m = (Matrix *) malloc(sizeof(Matrix));
    ASSERT_TRUE(expected_m != NULL);

    expected_m->matrix = NULL;
    expected_m->cols = 1;
    expected_m->rows = 1;
    expected_m->colsCapacity = 1;
    expected_m->rowsCapacity = 1;

    Matrix *test_m = matrix();

    EXPECT_EQ(expected_m->matrix, test_m->matrix);
    EXPECT_EQ(expected_m->cols, test_m->cols);
    EXPECT_EQ(expected_m->rows, test_m->cols);
    EXPECT_EQ(expected_m->rows, test_m->rows);
    EXPECT_EQ(expected_m->rowsCapacity, test_m->rowsCapacity);
    EXPECT_EQ(expected_m->colsCapacity, test_m->colsCapacity);

    free(expected_m);
    free(test_m);
}

TEST(matrix_storage, get_size) {
    Matrix *test_m = matrix();
    ASSERT_TRUE(test_m != NULL);

    FILE *test_input = fmemopen(string_rect_matrix, strlen(string_rect_matrix), "r");
    ASSERT_TRUE(test_input != NULL);

    getSizeTest(test_m, test_input);

    EXPECT_EQ(test_m->rows, defsult_rows);
    EXPECT_EQ(test_m->cols, default_cols);

    free(test_m);
}

TEST(matrx_storage, fill_storage) {
    Matrix *test_m = matrix();
    ASSERT_TRUE(test_m != NULL);

    FILE *test_input = fmemopen(string_rect_matrix, strlen(string_rect_matrix), "r");
    ASSERT_TRUE(test_input != NULL);

    fillMatrixTest(test_m, test_input);

    EXPECT_EQ(test_m->rows, defsult_rows);
    EXPECT_EQ(test_m->cols, default_cols);
    for (size_t i = 0; i < defsult_rows; ++i) {
        for (size_t j = 0; j < default_cols; ++j) {
            EXPECT_EQ(test_m->matrix[i][j], default_rect_matrix[i][j]);
        }
    }

    free(test_m);
}
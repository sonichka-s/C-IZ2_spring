#include <gtest/gtest.h>

extern "C" {
#include "mirroring.h"
}

size_t default_cols = 3;
size_t defsult_rows = 2;

int default_rect_matrix[2][3] = {{0,1, 2},
                                 {3, 4, 5} };
int mirrored_matrix[2][3] = {{4, 1, 2},
                             {3, 0, 5}};
int empty_rect_matrix;
char string_rect_matrix[] = "0 1 2\n3 4 5";

TEST(mirroring, mirroring_sync) {
    Matrix *m = matrix();
    ASSERT_TRUE(m != NULL);

    FILE *test_input = fmemopen(string_rect_matrix, strlen(string_rect_matrix), "r");
    ASSERT_TRUE(test_input != NULL);

    fillMatrixTest(m, test_input);
    mirroring(m);

    for (size_t i = 0; i < defsult_rows; ++i) {
        for (size_t j = 0; j < default_cols; ++j) {
            EXPECT_EQ(m->matrix[i][j], mirrored_matrix[i][j]);
        }
    }
}

TEST(mirroring, stress_test_mirroring) {

}
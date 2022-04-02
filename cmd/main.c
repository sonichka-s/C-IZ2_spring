#include "stdio.h"
#include "unistd.h"
#include "mirroring.h"
#include "matrix_storage.h"

int main() {
    FILE *f = fopen("../input_matrix.txt", "r");
    Matrix *m = matrix();
    fillMatrix(m, f);

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf("%i ", m->matrix[i][j]);
        }

    }
    mirroring(m);
    freeMatrix(&m);
}
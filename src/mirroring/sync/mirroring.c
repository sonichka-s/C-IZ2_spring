#include "../mirroring.h"

void mirroring(Matrix *m) {
    int buf = 0;

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->rows - i; ++j) {
            buf = m->matrix[i][j];
            m->matrix[i][j] = m->matrix[m->rows - j - 1][m->rows - i - 1];
            m->matrix[m->rows - j - 1][m->rows - i - 1] = buf;
        }
    }
}
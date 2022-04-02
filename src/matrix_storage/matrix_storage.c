#include "stdlib.h"
#include "matrix_storage.h"
#define INIT_SIZE 10

Matrix *matrix() {
    Matrix *buf = (Matrix *) malloc(sizeof(Matrix));

    buf->matrix = NULL;
    buf->cols = 1;
    buf->rows = 1;
    buf->rowsCapacity = 1;
    buf->colsCapacity = 1;

    return buf;
}

void getSize(Matrix *m, FILE *f) {
    while (!(feof(f))) {
        updateMatrix(m);
        int val = 0;
        fscanf(f, "%i", &val);

        if (!(feof(f))) {
            if (fgetc(f) != '\n') {
                m->cols += 1;
            } else {
                m->cols = 1;
                m->rows += 1;
            }
        }
    }
}

void getSizeTest(Matrix *m, FILE *f) {
    while (!(feof(f))) {
        updateMatrix(m);
        fscanf(f, "%i", &(m->matrix[m->rows - 1][m->cols - 1]));

        if (!(feof(f))) {
            if (fgetc(f) != '\n') {
                m->cols += 1;
            } else {
                m->cols = 1;
                m->rows += 1;
            }
        }
    }
}

void updateMatrix(Matrix *m) {
    if (m == NULL)
        return;

    if (m->matrix == NULL)
        m->matrix = (int **) malloc(sizeof(int *) * INIT_SIZE);


    if(m->rows + 1 >= m->rowsCapacity) {
        m->rowsCapacity *= 2;
        m->matrix = (int **) realloc(m->matrix, sizeof(int *) * m->rowsCapacity);

        if (m->matrix == NULL)
            return;
    }

    m->matrix[m->rows - 1] = (int *) malloc(sizeof(int));
}

void fillMatrix(Matrix *m, FILE *f) {
    getSize(m, f);
    fseek( f, 0, SEEK_SET );

    while (!(feof(f))) {
        for (int i = 0; i < m->rows; ++i) {
            for (int j = 0; j < m->cols; ++j) {
                fscanf(f, "%i", &(m->matrix[i][j]));
            }
        }
    }
}

void fillMatrixTest(Matrix *m, FILE *f) {
    getSizeTest(m, f);
    fseek( f, 0, SEEK_SET );

    while (!(feof(f))) {
        for (int i = 0; i < m->rows; ++i) {
            for (int j = 0; j < m->cols; ++j) {
                fscanf(f, "%i", &(m->matrix[i][j]));
            }
        }
    }
}

void freeMatrix(Matrix **m) {
    free(*m);
    (*m) = NULL;
}


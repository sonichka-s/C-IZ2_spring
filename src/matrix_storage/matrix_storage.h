#pragma once
#include "stdio.h"

typedef struct {
    int **matrix;
    size_t rows;
    size_t cols;
    size_t rowsCapacity;
    size_t colsCapacity;
} Matrix;

Matrix *matrix();
void fillMatrix(Matrix *m, FILE *f);
void fillMatrixTest(Matrix *m, FILE *f);
void updateMatrix(Matrix *m);
void getSizeTest(Matrix *m, FILE *f);
void getSize(Matrix *m, FILE *f);
void freeMatrix(Matrix **m);

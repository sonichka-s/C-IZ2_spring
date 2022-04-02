#include "../mirroring.h"
#include "sys/mman.h"
#include <sys/wait.h>
#include "unistd.h"
#include "stdlib.h"
#include "matrix_storage.h"

void mirroring(Matrix *m) {
    int proc_num = (int) sysconf(_SC_NPROCESSORS_CONF);
    size_t proc_start = 0;
    size_t proc_step = m->rows % proc_num;
    size_t proc_end = proc_step;
    pid_t proc = getpid();
    pid_t pid_arr[proc_num];

    Matrix *shared_matrix = (Matrix *)mmap(NULL, sizeof(Matrix), PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *(shared_matrix) = *(m);

    for (int i = 0; i < proc_num; ++i) {
        pid_arr[i] = fork();

        if (-1 == pid_arr[i]) {
            return;
        }

        if (pid_arr[i] == 0) {
            for (size_t j = proc_start; j < proc_end; ++j) {
                for (size_t k = 0; k < shared_matrix->rows - j; ++k) {
                    int buf = shared_matrix->matrix[j][k];
                    shared_matrix->matrix[j][k] = shared_matrix->matrix[shared_matrix->rows - k - 1][shared_matrix->rows - j - 1];
                    shared_matrix->matrix[shared_matrix->rows - k - 1][shared_matrix->rows - j - 1] = buf;
                }
            }

            exit(0);
        }

        proc_start = proc_end;
        proc_end += proc_step;
    }

    while (wait(0) > 0);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            m->matrix[i][j] = shared_matrix->matrix[i][j];
        }
    }

    munmap(shared_matrix, sizeof(Matrix));
}
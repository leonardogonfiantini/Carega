#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    double *data;
} Tensor;

Tensor *tensor_create(int rows, int cols);
Tensor *tensor_dot(Tensor *a, Tensor *b);

void tensor_set(Tensor *t, int row, int col, double value);
double tensor_get(Tensor *t, int row, int col);
void tensor_free(Tensor *t);
void tensor_randomize(Tensor *t);
void tensor_print(Tensor *t);

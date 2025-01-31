#include "tensor.h"

Tensor *tensor_create(int rows, int cols) {
    
    if (rows == 0 || cols == 0) {
        printf("Row or Colums are setted to 0, please check it\n");
        return NULL;
    }

    Tensor *tensor = (Tensor *)malloc(sizeof(Tensor));
    tensor->rows = rows;
    tensor->cols = cols;

    tensor->data = (double *)malloc(sizeof(double) * rows * cols);

    return tensor;
}

Tensor *tensor_dot(Tensor *a, Tensor *b) {
    if (a == NULL || b == NULL) {
        printf("Tensor A or B is NULL \n");
        return NULL;
    }

    printf("ciao");
    return a;
}

void tensor_set(Tensor *t, int row, int col, double value) {
    if (t == NULL) {
        printf("Tensor is NULL\n");
        return;
    }

    t->data[row + col] = value;
}

double tensor_get(Tensor *t, int row, int col) {
    if (t == NULL) {
        printf("Tensor is NULL\n");
        return 0;
    }

    return t->data[row+col];
}

void tensor_free(Tensor *t) {
    free(t->data);
    free(t);
}

void tensor_randomize(Tensor *t) {
    if (t == NULL) {
        printf("Tensor is NULL \n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < t->rows * t->cols; i++) {
        t->data[i] = (double)rand() / RAND_MAX;
    }
}

void tensor_print(Tensor *t) {
    if (t == NULL) {
        printf("Tensor is NULL \n");
        return;
    }

    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            printf("%lf ", t->data[i * t->cols + j]);
        }
        printf("\n");
    }
}


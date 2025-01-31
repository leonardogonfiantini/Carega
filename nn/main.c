#include "./tensor/tensor.h"

int main() {
    Tensor *t = tensor_create(10, 10);
    tensor_randomize(t);
    tensor_print(t);
    tensor_free(t);
}
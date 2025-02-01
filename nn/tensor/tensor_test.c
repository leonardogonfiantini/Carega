#include <check.h>
#include "tensor.h"

START_TEST(test_create_tensor) {
    Tensor *t = tensor_create(3, 3);
    ck_assert_ptr_nonnull(t);
    ck_assert_int_eq(t->rows, 3);
    ck_assert_int_eq(t->cols, 3);
    tensor_free(t);
} END_TEST

START_TEST(test_set_get_tensor) {
    Tensor *t = tensor_create(2, 2);
    tensor_set(t, 0, 0, 3.14);
    tensor_set(t, 0, 1, 0);
    tensor_set(t, 1, 0, 0);
    tensor_set(t, 1, 1, 2.71);
    tensor_print(t);
    
    ck_assert_double_eq(tensor_get(t, 0, 0), 3.14);
    ck_assert_double_eq(tensor_get(t, 1, 1), 2.71);
    
    tensor_free(t);
} END_TEST

START_TEST(test_randomize_tensor) {
    Tensor *t = tensor_create(100, 100);
    tensor_randomize(t);
    tensor_free(t);
} END_TEST

START_TEST(test_tensor_dot) {
    Tensor *a = tensor_create(2, 3);
    Tensor *b = tensor_create(3, 2);

    double values_a[] = {1, 2, 3, 4, 5, 6};  
    double values_b[] = {7, 8, 9, 10, 11, 12}; 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            tensor_set(a, i, j, values_a[i * 3 + j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            tensor_set(b, i, j, values_b[i * 2 + j]);
        }
    }

    Tensor *result = tensor_dot(a, b);

    tensor_print(a);
    tensor_print(b);
    tensor_print(result);

    ck_assert_ptr_nonnull(result);
    ck_assert_double_eq_tol(tensor_get(result, 0, 0), 58, 1e-6); 
    ck_assert_double_eq_tol(tensor_get(result, 0, 1), 64, 1e-6); 
    ck_assert_double_eq_tol(tensor_get(result, 1, 0), 139, 1e-6); 
    ck_assert_double_eq_tol(tensor_get(result, 1, 1), 154, 1e-6); 

    tensor_free(a);
    tensor_free(b);
    tensor_free(result);
}
END_TEST


Suite *tensor_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Tensor");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_tensor);
    tcase_add_test(tc_core, test_set_get_tensor);
    tcase_add_test(tc_core, test_randomize_tensor);
    tcase_add_test(tc_core, test_tensor_dot);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int no_failed;
    Suite *s;
    SRunner *sr;

    s = tensor_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    no_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

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
    tensor_set(t, 1, 1, 2.71);
    tensor_print(t);
    
    ck_assert_double_eq(tensor_get(t, 0, 0), 3.14);
    ck_assert_double_eq(tensor_get(t, 1, 1), 2.71);
    
    tensor_free(t);
} END_TEST

Suite *tensor_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Tensor");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_tensor);
    tcase_add_test(tc_core, test_set_get_tensor);
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

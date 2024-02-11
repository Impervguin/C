#include <check.h>
#include "check_mat.c"
#include "check_mat_op.c"

int main(void) {
    int no_failed = 0;                                            
    SRunner *runner; 

    runner = srunner_create(check_null_suite());          
    srunner_add_suite(runner, swap_suite());
    srunner_add_suite(runner, create_free_suite());
    srunner_add_suite(runner, sub_matrix_rows_suite());
    srunner_add_suite(runner, mult_row_suite());
    srunner_add_suite(runner, add_suite());
    srunner_add_suite(runner, mult_matrix_suite());
    srunner_add_suite(runner, inv_matrix_suite());


    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;  
}

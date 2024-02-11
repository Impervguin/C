#include <check.h>
#include "check_fibonacci.c"
#include "check_arr.c"

int main(void) {
    int no_failed = 0;                                            
    SRunner *runner; 

    runner = srunner_create(fibonacci_suite());
    srunner_add_suite(runner, extend_suite());          


    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;  
}

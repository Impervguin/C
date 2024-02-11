#include <check.h>
#include "check_sort.c"

int main(void) {
    int no_failed = 0;                                            
    SRunner *runner; 

    runner = srunner_create(compare_suite());          
    srunner_add_suite(runner, sort_suite());
    srunner_add_suite(runner, key_suite());


    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;  
}

#include <check.h>
#include "check_film.c"
#include "check_film_arr.c"

int main(void) {
    int no_failed = 0;                                            
    SRunner *runner; 

    runner = srunner_create(compare_suite());
    srunner_add_suite(runner, find_place_suite());
    srunner_add_suite(runner, insert_suite());
    srunner_add_suite(runner, gen_field_suite());


    srunner_run_all(runner, CK_NORMAL);  
    no_failed = srunner_ntests_failed(runner); 
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;  
}

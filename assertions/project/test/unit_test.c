#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "../include/stats.h"

#define INPUT_AMOUNT 3

static void run_tests(const int arrays[INPUT_AMOUNT][5], const unsigned length_arrays[], const int results[])
{
    unsigned i;

    int res;
    for (i = 0; i < INPUT_AMOUNT; ++i) {
        res = mean(arrays[i], length_arrays[i]);
        
        puts("-----------------------------");
        printf("Tescase[%u]:\n", i);
        printf("Tested result: %i | Hoped result: %i\n", res, results[i]);
        assert(res == results[i] && "Test faild");
        printf("Test passed\n");
    }
}


int main()
{
    const int arrays[INPUT_AMOUNT][5] = {{1, 2, 3, 4, 5}, {1, 2, 3}, {1, 2}};
    const unsigned length_arrays[INPUT_AMOUNT] = {5, 3, 2};
    const int results[INPUT_AMOUNT] = {3, 2, 1};

    
    run_tests(arrays, length_arrays, results);
    
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include <unistd.h>
#include <sys/time.h> // to manipulate miliseconds

#include "../include/stats.h"

#define AMOUNT_TESTS 10
#define MAX_LENGTH 100
#define MAX_NUM 1000


/* print_array: Print the array to test */
static void print_array(const int arr[], const unsigned length)
{
    unsigned i;

    printf(" {");
    for (i = 0; i < length; ++i) {
        if (i == length - 1) {
            printf("%i", arr[i]);
            break;
        }
        printf("%i, ", arr[i]);
    }
    puts("}");
}

/* run_test: just run the generate test */
static int run_test(const int array[], const unsigned length)
{
    return mean(array, length);
}

/* current_timestamp: To returnt he time in miliseconds */
static long long current_timestamp()
{
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}


/* run_random_tests: To run the randome tests */
static void generate_random_tests()
{
    unsigned length, number_tests, i;
    time_t t;
    
    for (number_tests = 0; number_tests < AMOUNT_TESTS; ++number_tests) {
        srand((unsigned) current_timestamp());
        length = rand() % MAX_LENGTH;
        
        int arr[length];
        for (i = 0; i < length; ++i)
            arr[i] = rand() % MAX_NUM;

        puts("-----------------------------");
        printf("Testcase[%u]\n", number_tests);
        printf("Length: %u\n", length);
        printf("arr: ");
        print_array((const int *) arr, (const int) length);
        printf("result: %i\n", run_test(arr, length));
        
        usleep(25000); /* sleep 1 mili second */
    }
}

    
int main()
{
    generate_random_tests();
    return 0;
}




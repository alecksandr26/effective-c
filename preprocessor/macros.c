#include <stdio.h>

int sumI(int arr[], int len)
{
    int res, i;

    for (res = i = 0; i < len; ++i)
        res += arr[i];

    return res;
}

float sumF(float arr[], int len)
{
    float res;
    int i;

    res = 0.0;
    for (i = 0; i < len; ++i)
        res += arr[i];

    return res;
}


/* Include the header file */
#include "lib.h"



/* Here the compiler will read this directives */
#if __STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>

#elif POSIX_THREADS == 200809L
#include <pthread.h>

#else
/* The directive error returns this message */ 
#error Neither <threadxbs.h> nor <pthread.h> is available

#endif


int main()
{
    struct Bar mybar;
    int arri[] = {1, 2, 3, 4, 5}, resi;
    float arrf[] = {1.5, 1.5}, resf;

    mybar.amount = 0;

    printf("%i\n", bar_amount(&mybar));

    printf("%i\n", max(1, 2));
    printf("%f\n", max(1.2, 1.5));
    printf("%c\n", max('a', 'b'));

    resi = sum(arri, 5);
    resf = sum(arrf, 2);

    printf("%i\n", resi);
    printf("%f\n", resf);
    
    return 0;
}



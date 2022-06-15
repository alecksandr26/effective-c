#include <assert.h>
#include <stdlib.h>

#include "../include/stats.h"

int __meani(const int *arr, const unsigned length)
{
    int sum;
    unsigned i;

    assert(arr != NULL && "Error: 'arr' can't be NULL");
    assert(length != 0 && "Error: 'length' can't be 0");

    for (sum = i = 0; i < length; ++i)
        sum += arr[i];

    return sum / length;
}



long __meanl(const long *arr, const unsigned length)
{
    long sum;
    unsigned i;

    assert(arr != NULL && "Error: 'arr' can't be NULL");
    assert(length != 0 && "Error: 'length' can't be 0");

    sum = 0;
    for (i = 0; i < length; ++i)
        sum += arr[i];

    return sum / length;
}

unsigned __meanu(const unsigned *arr, const unsigned length)
{
    unsigned sum, i;

    assert(arr != NULL && "Error: 'arr' can't be NULL");
    assert(length != 0 && "Error: 'length' can't be 0");

    for (i = sum = 0; i < length; ++i)
        sum += arr[i];

    return sum / length;
}


float __meanf(const float *arr, const unsigned length)
{
    float sum;
    unsigned i;
    
    assert(arr != NULL && "Error: 'arr' can't be NULL");
    assert(length != 0 && "Error: 'length' can't be 0");

    sum = 0.0;
    for (i = 0; i < length; ++i)
        sum += arr[i];

    return sum / (float) length;
}









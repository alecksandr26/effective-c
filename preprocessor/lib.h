/* This is the way to write header files */

#ifndef __BAR_H__
#define __BAR_H__

/* This is how we can create a constant directive */

#define __BAR_MAX_ARR_NAME__

struct Bar {
    int amount;
    char barName[__BAR_MAX_ARR_NAME__];
};


/* This is how we can create functions with directive instruction */
#define bar_amount(bar) ((bar)->amount)


/* Returns the max value */
#define max(a, b) (a > b ? a : b)



/* This is generic definition */
#define sum(arr, len) _Generic((arr), \
                               int *: sumI(arr, len),  \
                               float *: sumF(arr, len) \
                               )


#endif






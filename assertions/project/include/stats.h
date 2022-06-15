#ifndef __STATS_H__
#define __STATS_H__


long __meanl(const long *arr, const unsigned length);
unsigned __meanu(const unsigned *arr, const unsigned length);
float __meanf(const float *arr, const unsigned length);
int __meani(const int *arr, const unsigned length);



/* mean: Returns the mean value from an array
   arr: The array that contents all the elements
   length: Is the length of the array
   complexity: is O(n) where n is the number of elements 
*/
#define mean(arr, length) _Generic((arr), \
                                   const int * : __meani((const int *) arr, length),  \
                                   const long * : __meanl((const long *) arr, length),  \
                                   const unsigned * : __meanu((const unsigned *) arr, length), \
                                   const float * : __meanf((const float *) arr, length)  \
                                   )


#endif

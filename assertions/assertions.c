#include <stdio.h>

/* To create assertions you sould to include this */
#include <assert.h>
#include <limits.h>

#define num 1

/* If we uncomment this code we are going to dissable all the assertions */
#undef assert
#define assert(ignore) ((void)0)

struct packed {
    unsigned int i;
    char *p;
};


void clear_stdin()
{
    int c;
    do {
        c = getchar();
        static_assert(UCHAR_MAX < UINT_MAX, "FIO34-C violation");
    } while (c != EOF);
}


int main()
{
    int a, b;

    /* If then boolean expresion that I put inside of the function is false the program
       print the message and finishes with its execution, another thing, this only works
       with define values
    */
    static_assert(num == 1, "Error: num is different to 1");


    a = 2;
    b = 2;
   
    /* Now if we want to check the states of the variabels and objects we need to use assert function */
    assert(a > b && "'a' should't be lesser than 'b' variable or equal to 'b' variable");

    puts("No errors ");
    return 0;
}

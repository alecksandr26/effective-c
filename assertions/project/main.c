#include <stdio.h>


#include "include/stats.h"


enum MENU_OPTIONS {
    INT,
    UNSIGNED,
    LONG,
    FLOAT,
    EXIT
};


void calculate_meanint(unsigned length)
{
    int arr[length], res;
    unsigned i;
    
    for (i = 0; i < length; ++i) {
        printf("Put element %u: ", i + 1);
        scanf("%i", &arr[i]);
    }

    res = mean((const int *) arr, length);
    
    printf("res: %i\n", res);
}

void calculate_meanunsigned(unsigned length)
{
    unsigned arr[length], res;
    unsigned i;
    
    for (i = 0; i < length; ++i) {
        printf("Put element %u: ", i + 1);
        scanf("%u", &arr[i]);

    }
    
    res = mean((const unsigned *) arr, length);
    printf("res: %u\n", res);
}

void calculate_meanintlong(unsigned length)
{
    long arr[length], res;
    unsigned i;
    
    for (i = 0; i < length; ++i) {
        printf("Put element %u: ", i + 1);
        scanf("%li", &arr[i]);
        
    }
    
    res = mean((const long *) arr, length);
    printf("res: %li\n", res);
}

void calculate_meanfloat(unsigned length)
{
    float arr[length], res;
    unsigned i;
    
    for (i = 0; i < length; ++i) {
        printf("Put element %u: ", i + 1);
        scanf("%f", &arr[i]);
    }

    
    res = mean((const float *) arr, length);
    printf("res: %f\n", res);
}


int main()
{
    unsigned op, length;
    
    do {
        puts("What type of mean do you want to do: ");
        puts("[1] int");
        puts("[2] unsigned");
        puts("[3] long");
        puts("[4] float");
        puts("\n[5] exit");
        
        printf("\n>>> ");
        scanf("%u", &op);
        fflush(stdin);

        if (op - 1 < EXIT) {
            printf("Put the amount of elemetns: ");
            scanf("%u", &length);
            fflush(stdin);
        }
        
        switch (op - 1) {
        case INT:
            calculate_meanint(length);
            break;
        case UNSIGNED:
            calculate_meanunsigned(length);
            break;
        case LONG:
            calculate_meanintlong(length);
            break;
        case FLOAT:
            calculate_meanfloat(length);
            break;
        }
        
    } while (op - 1 < EXIT);
    return 0;
}

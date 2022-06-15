#include <stdio.h>

/* External definition */
extern void swap();

/* This array can be linked as external */
int buff[2] = {1, 2};

/* This function only will works on the scope of this file */
static int sum()
{
    static int sum = 0;
    
    sum += buff[0] + buff[1];
    
    return sum;
}


int main()
{
    swap();
    
    printf("%i\n", buff[0]);
    printf("%i\n", buff[1]);

    printf("%i\n", sum());
    printf("%i\n", sum());
    return 0;
}




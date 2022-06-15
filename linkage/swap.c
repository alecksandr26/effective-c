#include <stdio.h>

/* Here we are linking the declaration */
extern int buff[];


/* This version of sum only belongs to this files */
static void sum()
{
    printf("Hello from swap from sum\n");
}


void swap()
{
    int temp;

    /* We can manipulate and get access without problems */
    temp = buff[1];
    buff[1] = buff[0];
    buff[0] = temp;
    
    sum();
}




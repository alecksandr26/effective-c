#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include "include/is_prime.h"



/* print_help: To print the usage of how to use the program */
static void print_help()
{
    printf("primetest num1 [num2 num3 ... numN]\n");
    printf("Tests positive integers for primality. Supports testing ");
    printf("numbers in the range [2-%llu]\n", ULLONG_MAX);
}



/* convert_arg: To convert argument to a real val */
static bool convert_arg(const char *arg, unsigned long long *val)
{
    char *end;

    errno = 0;
    *val = strtoull(arg, &end, 10);

    /* To check if there is an error */
    if ((*val == ULLONG_MAX) && errno)
        return false;
    
    if (*val == 0 && errno)
        return false;

    if (end == arg)
        return false;
    
    if (*val <= 1)
        return false;

    return true;
}



/* convert_command_line_args: Convert all the arguments to a values */
static unsigned long long *convert_command_line_args(int argc, const char *argv[], size_t *num_args)
{
    unsigned long long *args, one_arg;
    bool failed_conversion;
    int i;
    
    *num_args = 0;
    if (argc <= 1) {
        print_help();
        return NULL;
    }

    args = (unsigned long long *)malloc(sizeof(unsigned long long) * (argc - 1));
    failed_conversion = (args == NULL);
    for (i = 1; i < argc && !failed_conversion; ++i) {
        failed_conversion |= !convert_arg(argv[i], &one_arg);
        args[i - 1] = one_arg;
    }

    if (failed_conversion) {
        free(args);
        print_help();
        return NULL;
    }

    *num_args = argc - 1;
    return args;
}



int main(int argc, char *argv[])
{
    size_t num_args, i;
    unsigned long long *vals;
    
    vals = convert_command_line_args(argc, (const char **) argv, &num_args);
    if (!vals)
        return EXIT_FAILURE;
    
    for (i = 0; i < num_args; ++i) {
        printf("%llu is %s.\n", vals[i],
               is_prime(vals[i], 100) ? "probably prime" : "not prime");
    }
    
    free(vals);
    
    return EXIT_SUCCESS;
}

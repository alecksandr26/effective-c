#include "../include/is_prime.h"

/*
  Some private methods 
 */


/* power: To calculate the power in number */
static unsigned long long power(unsigned long long x, unsigned long long y, unsigned long long p)
{
    unsigned long long result;
    

    result = 1;
    x %= p;
    while (y) {
        if (y & 1)
            result = (result * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }

    return result;
}



/* miller_rabin_test: To test the algorithm */
static bool miller_rabin_test(unsigned long long d, unsigned long long n)
{
    unsigned long long a, x;

    a = 2 + rand() % (n - 4);
    x = power (a, d, n);
    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}


/* is_prime: Is the function to know if is prime or not */
bool is_prime(unsigned long long n, unsigned int k) {
    unsigned long long d;
    
    if (n <= 1 || n == 4)
        return false;
    
    if (n <= 3)
        return true;
    
    d = n - 1;
    
    while (d % 2 == 0)
        d /= 2;
    
    for (; k != 0; --k) 
        if (!miller_rabin_test(d, n))
            return false;

    return true;
}



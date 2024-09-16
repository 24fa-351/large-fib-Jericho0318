#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
unsigned long long int fib_wrapper[100000000];
unsigned long long int fib_r_provider(unsigned long long int n)
{
    if (n == 0 || n == 1) {return 0;}
    if (n == 2) {return 1;}
    if (fib_wrapper[n] != 0) {return fib_wrapper[n];}
    else
    {
        if (fib_r_provider(n - 1) > ULLONG_MAX - fib_r_provider(n - 2))
        {
            printf("Error: overflow\nMax value: %llu\n", fib_r_provider(n - 1));
            exit(EXIT_FAILURE);
        }
    	fib_wrapper[n] = fib_r_provider(n - 1) + fib_r_provider(n - 2);
        return fib_wrapper[n];
    }
}

unsigned long long int fib_i_provider(unsigned long long int n)
{
    unsigned long long int first = 0, second = 1;
    if (n == 0) {return 0;}
    if (n == 1 || n == 2) {return 1;}
    if (fib_wrapper[n] != 0) {return fib_wrapper[n];}
    else
    {
    	for (int i = 2; i < n; ++i)
    	{
    		if (second > ULLONG_MAX - first)
            {
                printf("Error: overflow\nMax value: %llu\n", second);
                exit(EXIT_FAILURE);
            }
    		fib_wrapper[n] = first + second;
    		first = second;
    		second = fib_wrapper[n];
    	}
    }
    return fib_wrapper[n];
}

int main(int argc, char *argv[])
{
   unsigned long long int num = atoi(argv[1]);
   if (!strcmp(argv[2], "i"))
   {
   	printf("%llu\n", fib_i_provider(num));
   } else if (!strcmp(argv[2], "r")) {
        printf("%llu\n", fib_r_provider(num));
   }
   return 0;
}

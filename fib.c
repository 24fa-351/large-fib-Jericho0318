#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

uint64_t fib_r(uint64_t num)
{
    if (num == 0 || num == 1) {return 0;}
    if (num == 2) {return 1;}
    else
    {
        if (fib_r(num - 1) > ULLONG_MAX - fib_r(num - 2))
        {
            printf("Error: overflow\nMax value: %lu\n", fib_r(num - 1));
            exit(1);
        }
    	return fib_r(num - 1) + fib_r(num - 2);
    }
}

uint64_t fib_i(uint64_t num)
{
    uint64_t first = 0, second = 1, sum = 0;
    if (num == 0) {return 0;}
    if (num == 1 || num == 2) {return 1;}
    else
    {
    	for (int i = 2; i < num; ++i)
    	{
    		if (second > ULLONG_MAX - first)
            {
                printf("Error: overflow\nMax value: %lu\n", second);
                exit(1);
            }
    		sum = first + second;
    		first = second;
    		second = sum;
    	}
    }
    return sum;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        perror("Provide 3 arguments: ./<filename> <num> <i or r>\n");
        exit(1);
    }

    uint64_t get_num = atoi(argv[1]);

    if (!strcmp(argv[2], "i")) {
        printf("%lu\n", fib_i(get_num));
    } else if (!strcmp(argv[2], "r")) {
        printf("%lu\n", fib_r(get_num));
    } else {
        perror("Choose between i or r in argv[2]\n");
        exit(1);
    }
    return 0;
}
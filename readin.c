#include<stdio.h>
static int clear_stdin(void)
{
    while (getchar() != '\n');
    return 0;
}

int read_from_stdin(int* const N, int* const seed)
{
    do {
        printf("please input the number of points "
               "you would like to generate:");
    }
    while (!(scanf("%d", N) || clear_stdin()));
    
    do {
        printf("please input a seed for your PRNG:");
    } while (!(scanf("%d", seed) || clear_stdin()));

    return *N < 0 || *seed < 0;
}



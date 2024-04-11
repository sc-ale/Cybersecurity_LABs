#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int modulo(int a, int b){
    int m = a % b;
    if(m < 0)
        m = (b < 0) ? m - b : m + b;
    return m;
}

int multliplicativeInverse(int a, int b) {
    int a0 = a;
    int b0 = b;
    int t0 = 0;
    int t = 1;
    int q = (int)(a0/b0);
    int r = a0 - (q*b0);
    int temp;

    while (r>0) {
        temp = modulo((t0 - (q*t)), a);
        t0 = t;
        t = temp;
        a0 = b0;
        b0 = r;
        q = (int)(a0/b0);
        r = a0 - q*b0;
    }

    if (b0 != 1) {
        printf("No multiplicative inverse\n");
        return -1;
    }

    printf("Multiplicative inverse of %i mod %i is %d\n", b, a, t);
    return t;
}


int main(int argc, const char* argv[]){
    if (argc != 3) {
        errno=EINVAL;
        perror("Invalid arguments number");
        exit(EXIT_FAILURE);
    } 
    
    int b = atoi(argv[1]);
    int a = atoi(argv[2]);

    if (a < 0 || b < 0) {
        errno=EINVAL;
        perror("arguments must be positive");
        exit(EXIT_FAILURE);
    }

    multliplicativeInverse(a, b);
} 

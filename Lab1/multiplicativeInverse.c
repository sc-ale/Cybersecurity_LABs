#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int multliplicativeInverse(int a, int b) {
    int a0 = a;
    int b0 = b;
    int t0 = 0;
    int t = 1;
    
    
    int q = floor(a0/b0);
    int r = a0 - q*b0;
    int temp;

    while (r>0) {
        temp = (t0 - q*t) % a;
        t0 = t;
        t = temp;
    
        a0 = b0;
        b0 = r;
        q = floor(a0/b0);
        r = a0 - q*b0;
    }

    if (b0 != 1) {
        printf("No multiplicative inverse\n");
        return -1;
    }

    printf("Multiplicative inverse of %d mod %d is %d\n", a, b, t);
    return t;
}


int main(int argc, const char* argv[]){
    if (argc != 3) {
        perror("invalid argument numbers\n");
        return EINVAL;
    } 
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (a < 0 || b < 0) {
        perror("arguments must be positive\n");
        return EINVAL;
    }

    multliplicativeInverse(a, b);

} 

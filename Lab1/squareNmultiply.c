#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int squareNmultiply(int x, int c, int n) {
    int z = 1;
    for (int i = 0; i < c; i++) {
        z = (z * z) % n;
        if ((c & (1 << i)) != 0) {
            z = (z * x) % n;
        }
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

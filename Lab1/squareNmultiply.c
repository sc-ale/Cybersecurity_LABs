#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define IS_BIT_SET(n,x) ((n & (1 << x)))


unsigned int binaryLenght(int c) {
    unsigned int bits;                              
    unsigned var = (c<0) ? -c : c;              
    for (bits = 0; var!=0; bits++) var >>= 1;                                    
    return bits;
}


int squareNmultiply(int x, int c, int n) {
    int z = 1;
    
    for (int i = 0; i < binaryLenght(c)-1; i++) {
        z = (z * z) % n;
        if (IS_BIT_SET(c, i)) {
            z = (z * x) % n;
        }
    }
    printf("%d^%d mod %d = %d\n", x, c, n, z);
    return z;
}


int main(int argc, const char* argv[]){
    if (argc != 4) {
        perror("invalid argument numbers\n");
        return EINVAL;
    } 
    
    int x = atoi(argv[1]);
    int c = atoi(argv[2]);
    int n = atoi(argv[3]);

    if (n < 0) {
        perror("argument must be positive\n");
        return EINVAL;
    }

    squareNmultiply(x, c, n);

} 

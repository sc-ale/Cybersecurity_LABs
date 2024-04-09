#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//result[3] = r,s,t
void euclideanAlgExt(int a, int b, int* result) {
    int a0 = a;
    int b0 = b;
    int t0 = 0;
    result[2] = 1;
    int s0 = 1;
    result[1] = 0;
    int q = floor(a0/b0);
    result[0] = a0 - q*b0;
    int tmp;

    while (result[0]>0) {
        tmp = t0 - q*result[2];
        t0 = result[2];
        result[2] = tmp;
        tmp = s0 - q*result[1];
        s0 = result[1];
        result[1] = tmp;
        a0 = b0;
        b0 = result[0];
        q = floor(a0/b0);
        result[0] = a0 - q*b0;
    }
    result[0] = b0;
    printf("gcd(%d,%d) = %d*%d+%d*%d = %d\n", a, b, result[1], a, result[2], b, result[0]);
}


int main(int argc, const char* argv[]){

    if (argc != 3) {
        perror("invalid argument numbers\n");
        return EINVAL;
    } 
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int result[3] = {0,0,0};

    if (a < 0 || b < 0) {
        perror("arguments must be positive\n");
        return EINVAL;
    }

    euclideanAlgExt(a, b, result);
    return 0;
} 

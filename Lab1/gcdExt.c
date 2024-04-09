#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int* euclideanAlgExt(int a, int b) {
    int a0 = a;
    int b0 = b;
    int t0 = 0;
    int t = 1;
    int s0 = 1;
    int s = 0;
    int q = floor(a0/b0);
    int r = a0 - q*b0;
    int temp;

    while (r>0) {
        temp = t0 - q*t;
        t0 = t;
        t = temp;
        temp = s0 - q*s;
        s0 = s;
        s = temp;
        a0 = b0;
        b0 = r;
        q = floor(a0/b0);
        r = a0 - q*b0;
    }
    r = b0;
    printf("gcd:(%d,%d) = %d*%d+%d*%d = %d\n", a, b, s, a, t, b, r);
    
    int *result = {r,s,t};
    return result;
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

    euclideanAlgExt(a, b);

} 

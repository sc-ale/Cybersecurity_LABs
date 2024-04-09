#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct listOfNumbers
{
    int number;
    struct listOfNumbers* next;
};

struct listOfNumbers* addNumber(struct listOfNumbers* head, int number) {
    struct listOfNumbers* newNum = malloc(sizeof(struct listOfNumbers));
    if (newNum == NULL) {
        perror("malloc failed\n");
        exit(EXIT_FAILURE);
    };
    newNum->next = NULL;
    newNum->number = number;

    if (head == NULL) {
        head = newNum;
    } else {
        struct listOfNumbers* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNum;
    }
    return head;
}

void printQuotients(struct listOfNumbers* head) {
    struct listOfNumbers* current = head;
    printf("Quotients (from 1 to m):\n");
    int i=1;
    while (current != NULL) {
        printf("q%d: %d\n", i, current->number);
        current = current->next;
        i++;
    }
}

void euclideanAlg(int a, int b) {

    struct listOfNumebers* allQuotients = NULL;    
    
    int qCurrent;
    int rPrec = a;
    int rCurrent = b;
    int rNew;
    
    while(rCurrent != 0) {
        qCurrent = floor(rPrec/rCurrent);
        rNew = rPrec - qCurrent*rCurrent;
        allQuotients = addNumber(allQuotients, qCurrent);
        rPrec = rCurrent;
        rCurrent = rNew;
    }

    printQuotients(allQuotients);
    printf("r: %d\n", rPrec);
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

    euclideanAlg(a, b);
    return 0;
} 

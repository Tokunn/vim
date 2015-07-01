#include <stdio.h>
#include <stdlib.h>

#define A_SIZE 10


/*----- printlist() -----*/
void printlist(int *a_p) {
    int i;
    for (i = 0; i < A_SIZE; i++) {
        printf("%d:", a_p[i]);
    }
    printf("\n");
}


/*----- qsorts() ------*/
void qsorts(int *a_p, int low, int high) {
    int i=low, j=high, tmp;
    int p = a_p[low];

    while (i <= j) {
        while (a_p[i] < p) {
            i++;
        }
        while (a_p[j] > p) {
            j--;
        }
        if (i<=j) {
            tmp = a_p[i];
            a_p[i] = a_p[j];
            a_p[j] = tmp;
            i++;
            j--;
        }
    }

    printlist(a_p);

    if (low < j) {
        qsorts(a_p, low, j);
    }
    if (high > i) {
        qsorts(a_p, i, high);
    }
}


/*----- main() -----*/
int main() {
    int a[] = {3, 9, 1, 6, 8, 7, 2, 5, 4, 0};
    printlist(a);

    qsorts(a, 0, A_SIZE-1);
    return EXIT_SUCCESS;
}

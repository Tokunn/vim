#include <stdio.h>
#include <stdlib.h>

#define A_SIZE 20


/*----- printlist() -----*/
void printlist(int *a_p) {
    int i;
    for (i = 0; i < A_SIZE; i++) {
        printf("%d:", a_p[i]);
    }
    printf("\n");
}


/*----- msorts() -----*/
void msorts(int *a, int p, int n) {
    int h = n/2;
    int i, j, k;
    int b[A_SIZE];
    if (n > 1) {
        msorts(a, p, h);
        msorts(a, p+h, A_SIZE-h);
        i = p;
        j = p + h;
        for (k=p; k < p+n-1; k++) {
            if ((i < p+h) && ((j>=p+n) || (a[i] <= a[j]))) {
                b[k] = a[i];
                i++;
            }
            else {
                b[k] = a[j];
                j++;
            }
        }
        for (i = 0; i < A_SIZE; i++) {
            a[i] = b[i];
        }
        printlist(a);
    }
}


/*----- main() -----*/
int main() {
    int a[] = {14, 1, 20, 18, 8, 11, 13, 10, 2, 19, 4, 15, 3, 17, 16, 5, 12, 9, 6, 7};
    printlist(a);

    msorts(a, 0, A_SIZE-1);

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define A_SIZE 20
//#define A_SIZE 10


/*----- printlist() -----*/
void printlist(int *a_p, int low, int high) {
    int i;
    for (i = low; i < high; i++) {
        printf("%d:", a_p[i]);
    }
    printf("\n");
}


/*----- msorts() -----*/
void msorts(int *a, int p, int n) {
    int i, j, k, h;
    int b[A_SIZE] = {0};
    if (n > 1) {
        h = n/2;

        msorts(a, p, h);
        msorts(a, p+h, n-h);

        i = p;
        j = p + h;

        for (k=p; k < p+n; k++) {
            if ((i < p+h) && ((j>=p+n) || (a[i] <= a[j]))) {
                b[k] = a[i];
                printf("a[i]\n");
                i++;
            }
            else {
                b[k] = a[j];
                printf("a[j]\n");
                j++;
            }
        }
        for (i = p; i < p+n; i++) {
            a[i] = b[i];
        }
        printf("A: ");
        printlist(a, 0, A_SIZE);
        printf("B: ");
        printlist(b, 0, A_SIZE);
    }
}


/*----- main() -----*/
int main() {
    int a[] = {14, 1, 20, 18, 8, 11, 13, 10, 2, 19, 4, 15, 3, 17, 16, 5, 12, 9, 6, 7};
    //int a[] = {3, 2, 5, 7, 1, 9, 6, 0, 4, 8};
    //int a[] = {3, 7, 8, 4, 2, 5, 1, 6, 9, 2, 0};
    printlist(a, 0, A_SIZE);

    msorts(a, 0, A_SIZE);

    return EXIT_SUCCESS;
}

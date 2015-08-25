#include <stdio.h>
#include <stdlib.h>

#define N 20

/*----- printlist() -----*/
void printlist(int *a_p, int low, int high) {
    int i;
    for (i = low; i < high; i++) {
        printf("%d:", a_p[i]);
    }
    printf("\n");
}

/*----- main() -----*/
int main(void) {
    int list[N];
    int low = 0, high = N, m, x, i;
    for (i = 0; i < N; i++) {
        list[i] = i+1;
    }
    printlist(list, 0, N);

    printf("Input Number : ");
    scanf("%d", &x);

    while (low <= high) {
        m = (low+high) / 2;
        if (list[m] == x) {
            printf("find at[%d]\n", m+1);
            break;
        }
        else if (list[m] > x) {
            high = m - 1;
        }
        else {
            low = m + 1;
        }
    }
    return EXIT_SUCCESS;
}

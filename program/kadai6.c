#include <stdio.h>
#include <stdlib.h>

#define NUM 20

/*----- printlist() -----*/
void printlist(int *a_p, int low, int high) {
    int i;
    for (i = low; i < high; i++) {
        printf("%d:", a_p[i]);
    }
    printf("\n");
}


/*----- bsorts() -----*/
void bsorts(int *a_p, int *list, int low, int high) {
    int i, j, tmp, tmp_list;
    for (i = low; i < high-1; i++) {
        for (j = high-1; j > i; j--) {
            if (a_p[j] < a_p[j-1]) {
                tmp = a_p[j-1];
                tmp_list = list[j-1];
                a_p[j-1] = a_p[j];
                list[j-1] = list[j];
                a_p[j] = tmp;
                list[j] = tmp_list;
            }
        }
        printlist(list, 0, NUM);
    }
}

/*----- main() -----*/
int main(void) {
    int list[] = {14, 1, 20, 18, 8, 11, 13, 10, 2, 19, 4, 15, 3, 17, 16, 5, 12, 9, 6, 7};
    int digit1_list[NUM];
    int digit2_list[NUM];
    int i;
    printlist(list, 0, NUM);

    // debug
    //bsorts(list, list, 0, NUM);
    //printf("[DEBUG] : ");
    //printlist(list, 0, NUM);

    // calc 1 digit
    for (i = 0; i < NUM; i++) {
        digit1_list[i] = list[i] - (list[i] / 10) * 10;
    }
    printf("[DEBUG] 1 digit: ");
    printlist(digit1_list, 0, NUM);

    // sort by bsort (1 digit)
    bsorts(digit1_list, list, 0, NUM);
    printlist(list, 0, NUM);

    // calc 2 digit
    for (i = 0; i < NUM; i++) {
        digit2_list[i] = (list[i] - digit1_list[i]) / 10;
    }
    printf("[DEBUG] 2 digit: ");
    printlist(digit2_list, 0, NUM);

    // sort by bsoort (2 digit)
    bsorts(digit2_list, list, 0, NUM);
    printlist(list, 0, NUM);

    return EXIT_SUCCESS;
}

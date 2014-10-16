/*      2R 21 Masato Suzuki     *
 *      Kadai2-2                */


#include <stdio.h>

int read_num() {
    printf("Which number are you looking for ? : ");
    int num = 0;
    scanf("%d", &num);
    return num;
}

void search_num( int num ) {
    int i, j;
    int data[2][5] = { {1, 3, 5, 7, 9}, {0, 2, 4, 6, 8} };
    int find_flag = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            if (data[i][j] == num) {
                printf("%d is in data[%d][%d]\n", num, i, j);
                find_flag = 1;
            }
        }
    }

    if (!find_flag) {
        printf("Sorry We Can't find The Number You Are Looking For :( \n");
    }
}

int main() {
    int num = read_num();
    search_num( num );

    return 0;
}

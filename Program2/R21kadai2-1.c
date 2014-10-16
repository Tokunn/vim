/*      2R 21 Masato Suzuki     *
 *      Kadai2-1                */


#include <stdio.h>

void read_score( int *score ) {
    int i;
    for (i = 0; i < 5; i++) {
        printf("Enter the score of student [No.%d] : ", i+1);
        scanf("%d", &score[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("\t#Check# Student score [No.%d] : %d\n", i+1, score[i]);
    }
}

double calc_average( int *score ) {
    int sum = 0;

    int i;
    for (i = 0; i < 5; i++) {
        sum += score[i];
    }

    double average = (double)sum / 5;
    return average;
}

int main() {
    int score[5];

    read_score( score );
    double average = calc_average( score );

    printf("%lf\n", average);

    return 0;
}

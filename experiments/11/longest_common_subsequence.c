#include<stdio.h>
#include<stdlib.h>

int lcs_dynamic(char x[9], char y[9], int size_x, int size_y) {
    int C[size_x][size_y], i, j;

    for(i = 0; i < size_x; i++) {
        C[i][0] = 0;
    }
    for(i = 0; i < size_y; i++) {
        C[0][i] = 0;
    }

    for(i = 0; i < size_x; i++) {
        for(j = 0; j < size_y; j++) {
            if (x[i] == y[j]) {
                C[i][j] = ((i - 1 < 0 || j - 1 < 0) ? 0 : C[i - 1][j - 1]) + 1;
            }
            else if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = (i - 1 > 0) ? C[i - 1][j]: 0;
            }
            else {
                C[i][j] = (j - 1 > 0) ? C[i][j - 1]: 0;
            }
        }
    }
    for(i = 0; i < size_x; i++) {
        for (j = 0; j < size_y; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return C[size_x - 1][size_y - 1];
}

void main() {
    char X[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B', 'C', 'D'};
    char Y[] = {'B', 'D', 'C', 'A', 'B', 'A', 'C', 'D', 'C'};
    int size_x = 9, size_y = 9;
    printf("Longest Common Subsecquence: %d\n", lcs_dynamic(X, Y, size_x, size_y));
}

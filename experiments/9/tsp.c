#include<stdio.h>
#include<stdlib.h>



void main() {
    int edges[4][4] = {
        {0, 3, 2, 1},
        {1, 0, 4, 4},
        {3, 2, 0, 3},
        {1, 2, 1, 0}
    };
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", edges[i][j]);
        }
        printf("\n");
    }
}

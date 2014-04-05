#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *get_alternative(int *board, int n, int m, int position, int replace_from) {
    int i, j, *alternative_board;
    if (position < 0 || position > n * m || replace_from < 0 || replace_from > n * m)
        return NULL;
    alternative_board = (int *) malloc(n * m * sizeof(int *)); 
    for(i = 0; i < n * m; ++i) 
        alternative_board[i] = board[i];
    j = alternative_board[replace_from];
    alternative_board[replace_from] = alternative_board[position];
    alternative_board[position] = j;
    return alternative_board;
}

void get_alternative_positions(int position, int n, int m, int *top, int *left, int *right, int *bottom) {
    *top = -1; *bottom = -1; *left = -1; *right = -1;
    if(position < 0 || position > n * m) {
        return;
    }
    if (position - n >= 0) *top = position - n;
    if (position + n < n * m) *bottom = position + n;
    if ((position - 1) % m != (m -1)) *left = position - 1;
    if ((position + 1) % m != 0) *right = position + 1;
}

float get_distance(int *output, int *current, int n, int m) {
    int i, j, x1, y1, x2, y2;
    float sum = 0.0f;
    float temp = 0.0f;
    for(i = 0; i < n * m; ++i) {
        x1 = (int) (i / n); 
        y1 = i % n;
        for(j = 0; j < n * m; ++j) {
            if(output[i] == current[j]) {
                x2 = (int) (j / n);
                y2 = j % n;
                break;
            }
        }
        temp = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        sum += temp; 
    }
    return sum;
}

/*
void main() {
    int top, left, right, bottom;
    int i, m = 4, n = 4;
    int *alternative;
    int values1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int values2[] = {1, 2, 3, 10, 5, 6, 7, 8, 9, 4, 11, 12, 13, 14, 15, 0};
    int values3[] = {4, 2, 3, 10, 5, 6, 7, 8, 9, 1, 11, 14, 13, 12, 15, 0};
    for (i = 0; i < m * n; i++) {
        printf("%3d", i);
        if (i % m == m -1) printf("\n");
    }
    for (i = 0; i < m * n; i++) {
        get_alternative_positions(i, m, n, &top, &left, &right, &bottom);
        printf("%2d: %2d, %2d, %2d, %2d\n", i, top, left, right, bottom);
    }
    float distance;
    distance = get_distance(values1, values2, n, m);
    printf("Distance Val1 and Val2: %f\n", distance);
    distance = get_distance(values1, values3, n, m);
    printf("Distance Val1 and Val3: %f\n", distance);
    alternative = get_alternative(values1, n, m, 15, 14);
    for (i = 0; i < m * n; i++) {
        printf("%3d", alternative[i]);
        if (i % m == m - 1) printf("\n");
    }
}
*/

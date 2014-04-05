#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif
#include "priority_queue.c"
#include "puzzle_util.c"

void display_board(int *board, int n, int m) {
    int i, j;
    for (i = 0; i < n * m; ++i) {
        printf("%2d ", board[i]);
        if (i % n == n - 1) printf("\n");
    }
}

long long hash(int *board, int n, int m) {
    int i, j;
    long long l = 0;
    long long temp; 
    for(i = 0; i < n * m; ++i) {
        temp = 1;
        for(j = 0; j < i; j++) {
            temp *= 10;
        }
        l += board[i] * temp;
    }
    return l;
}

void add_alternative_to_queue(int *output, int *board, int position, int new_position, int n, int m, Set *visited, List *path, PQ *pq) {
    int *alternative, node;
    long long _hash;
    List *n_path;
    Set *n_visited;
    float distance;
    alternative = get_alternative(board, n, m, position, new_position);
    _hash = hash(alternative, n, m);
    
    n_visited = set_copy(visited);
    n_path = list_copy(path);

    if(!set_exists(visited, _hash)) {
        node = alternative[position];
        distance = get_distance(output, alternative, n, m);
        set_add(n_visited, _hash, 0);
        list_add(n_path, node);
        offer(pq, distance, alternative, node, n_visited, n_path);
    }
}

void add_alternatives(int *output, int *board, int n, int m, Set *visited, List *path, PQ *pq) {
    int i, position = -1;
    int top, bottom, left, right;
    for (i = 0; i < m * n; ++i) {
        if (board[i] == 0) {
            position = i;
            break;
        }
    }
    if (position == -1) return;
    get_alternative_positions(position, n, m, &top, &left, &right, &bottom);
    if (top != -1) 
        add_alternative_to_queue(output, board, position, top, n, m, visited, path, pq);
    if (bottom != -1) 
        add_alternative_to_queue(output, board, position, bottom, n, m, visited, path, pq);
    if (left != -1) 
        add_alternative_to_queue(output, board, position, left, n, m, visited, path, pq);
    if (right != -1) 
        add_alternative_to_queue(output, board, position, right, n, m, visited, path, pq);
}

void main() {
    Set *visited; 
    List *path;
    PQ *pq;
    int n = 4, m = 4, node;
    long long initial_hash;
    datatype2 *d;
    float initial_distance;
    int output[] = {1, 2,  3,  4,  5,  6,  7,  8, 9, 10, 11, 12, 13, 14, 15, 0};
    int puzzle[] = {0, 12, 9, 13, 15, 11, 10, 14, 3,  7,  2,  5,  4,  8,  6, 1};
    visited = set_create();
    path = create_list();
    pq = create_PQ(10000);
    initial_hash = hash(puzzle, n, m);
    node = puzzle[0];
    set_add(visited, initial_hash, 0);
    list_add(path, node);
    initial_distance = get_distance(output, puzzle, n, m);
    offer(pq, initial_distance, puzzle, node, visited, path);
    while(!is_empty(pq)) {
        d = take(pq);
        printf("%f\n", d->key);
        add_alternatives(output, d->board , n, m, d->visited, d->path, pq);
    }
}

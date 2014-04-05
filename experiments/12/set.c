#include<stdio.h>
#include<stdlib.h>
#include "tree.c"

typedef struct _set {
    Node *root;
} Set;

Set *set_create() {
    Set *s = (Set *) malloc(sizeof(Set));
    s->root = NULL; 
    return s;
}

Set *set_copy(Set *s) {
    Set *n_s = (Set *) malloc(sizeof(Set));
    n_s->root = tree_copy(s->root); 
    return n_s;
}

void set_add(Set *s, long long key, int data) {
    int i, counter, found = 0;
    if(s->root == NULL) 
        s->root = create_node(key, data);
    else
        add(s->root, key, data);
}

int set_exists(Set *s, long long key) {
    if(search(s->root, key) != NULL) return 1;
    else return 0;
}

void set_remove(Set *s, long long key) {
    s->root = delete(s->root, key);
}

void set_display(Set *s) {
    print(s->root);
}

int set_empty(Set *s) {
    return s->root == NULL;
}

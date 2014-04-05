#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int length;
    int size;
    int *data;
} List;

List *create_list() {
    List *list = (List *) malloc(sizeof(List));
    list->length = 100;
    list->size = 0;
    list->data = (int *) malloc(list->length * sizeof(int *));
    return list;
}

List *list_copy(List *list) {
    int i, *new_data;
    List *new_list = (List *) malloc(sizeof(List));
    new_list->length = list->length;
    new_list->size = list->size;
    new_data = (int *) malloc(new_list->length * sizeof(int *));
    new_list->data = new_data;
    for (i = 0; i < list->size; ++i) {
        new_list->data[i] = list->data[i];
    }
    return new_list;
}

void list_add(List *list, int data) {
    int i, new_length, *new_data;
    if (list->size >= list->length) {
        new_length = 2 * list->length;
        new_data = (int *) malloc(new_length * sizeof(int *));
        for (i = 0; i < list->size; ++i) {
            new_data[i] = list->data[i];
        }
        free(list->data);
        list->data = new_data;
    }
    list->data[list->size] = data;
    list->size++;
}

int list_get(List *list, int position) {
    if (position >= list->size) {
        return -1;
    }
    return list->data[position];
}

int list_remove(List *list, int position) {
    int i, data;
    if (list->size <= position || position < 0) {
        return -1;
    }
    data = list->data[position];
    for(i = position; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return data;
}

void list_display(List *list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

/*
void main() {
    int i;
    List *list = create_list();
    for(i = 0; i < 200; i++) {
        list_add(list, i);
    }
    list_display(list);
    for(i = 0; i < 200; i++) {
        list_remove(list, 0);
        if (i % 10 == 0) {
            list_display(list);
            printf("\n");
        }
    }
    printf("***");
    list_display(list);
    printf("***");
    for(i = 0; i < 200; i++) {
        list_add(list, i);
    }
    list_display(list);

}
*/

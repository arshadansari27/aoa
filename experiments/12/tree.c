#include<stdio.h>
#include<stdlib.h>
#ifndef DATA_TYPE
#include "data.c"
#endif

typedef struct binary_tree_node {
    datatype *data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;
} Node;

Node *create_node(long long value, int data) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->data = (datatype *) malloc(sizeof(datatype));
    n->data->key = value;
    n->data->data = data;
    return n;
}

Node *tree_copy(Node *root) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = (datatype *) malloc(sizeof(datatype));
    n->data->key = root->data->key;
    n->data->data = root->data->data;
    n->left = tree_copy(root->left);
    n->right = tree_copy(root->right);
    return n;

}

Node *add(Node *root, long long data, int d) {
    if (root->data->key == data) {
        return;
    }
    else if (root->data->key < data) {
        if(root->right == NULL) {
            root->right = create_node(data, d);
            return root->right;
        }
        return add(root->right, data, d);
    }
    else {
        if(root->left== NULL) {
            root->left= create_node(data, d);
            return root->left;
        }
        return add(root->left, data, d);
    }
}

Node *search(Node *root, long long data) {
    if (root == NULL) {
        //printf("Not found\n");
        return NULL;
    }
    if (root->data->key < data) {
        return search(root->right, data);
    }
    else if(root->data->key > data){
        return search(root->left, data);
    }
    else {
        return root;
    }
}

void preorder(Node  *root, Node *parent, int count) {
    int i;
    if(root==NULL) return;
    for(i = 0; i < 2 * count; i++) printf(" ");
    if (parent != NULL) {
        if (parent->left == root) printf("L: ");
        else printf("R: ");
    }
    printf("%lld\n", root->data->key);
    preorder(root->left, root, count + 1);
    preorder(root->right, root, count + 1);
}

void print(Node *root) {
    int count = 0;
    preorder(root, NULL, count);
    printf("\n");
}

void clean(Node *node) {
    node->left = NULL;
    node->right = NULL;
    free((void *) node);
}

void destory(Node *root) {
    destory(root->left);
    destory(root->right);
    clean((void *) root);
}

Node *delete(Node *root, long long data) {
    Node *parent=NULL, *temp=NULL, *temp2=NULL, *node=NULL, *old_node=NULL;
    Node *previous=NULL;
    if (root== NULL) {
        printf("Tree is empty\n");
        return root;
    }

    temp = root;

    while(temp != NULL && temp->data->key != data) {
        temp2 = temp;
        if (temp->data->key > data) 
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (temp != NULL && temp->data->key == data) {
        node = temp;
        parent = temp2;
    }
    else {
        printf("Not found, so no delete of %lld\n", data);
        return root;
    }
    temp2 = NULL;
    old_node = node; 
    if (node->left == NULL && node->right == NULL) {
        node = NULL;
    }
    else if (node->left != NULL && node->right == NULL) {
        node = node->left;
    }
    else if (node->left == NULL && node->right != NULL) {
        node = node->right;
    }
    else {
        previous = node->left;
        temp = previous;
        temp2 = NULL;
        while(previous->right != NULL) {
            temp = previous;
            previous = previous->right;
        }
        printf("Previous [%lld], Temp[%lld], \n", previous->data->key, temp->data->key);
        if (temp != previous) {
            if(previous->left != NULL) {
                temp2 = previous->left;
            }
            else {
                temp2 = NULL;
            }
            if(temp->left == previous) temp->left = temp2;
            else temp->right = temp2;
            previous->left = node->left;
            previous->right = node->right;
        }
        else {
            previous->right = node->right;
        }
        node = previous;
        //printf("Node is previous now %d, [%d, %d]\n", node->data, node->left->data, node->right->data);
    }
    if (parent != NULL && parent != old_node) {
        if(parent->left == old_node)  {
            parent->left = node;
        }
         else {
            parent->right = node;
         }
    }
    else if (root == old_node) {
        root = node; 
    }
    else {
        printf("Yeah whatever\n");
    }
    clean(old_node);
    return root;
}

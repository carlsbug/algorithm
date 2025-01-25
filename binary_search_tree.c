#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

void traverse_inorder(struct Node* n){
    if (n == NULL){
        return;
    }
    traverse_inorder(n->left);
    printf("%d ", n->key);
    traverse_inorder(n->right);
} 

struct Node* insertNode(struct Node* n, int key){
    if (n == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        return newNode;
    }
    else if (key < n->key){
        return n->left = insertNode(n->left, key);
    }
    else {
        return n->right = insertNode(n->right, key);
    }
}

struct Node* search(struct Node* n, int key){
    if (n == NULL){
        return NULL;
    }
    else if (n->key == key){
        printf("found node, key: %d", n->key);
        return NULL;
    }
    else if (n->key > key){
        return search(n->left, key);
    }
    else{
        return search(n->right, key);
    }
}

int main(){
    struct Node tree = {5, NULL, NULL};
    struct Node *ptr = &tree;

    insertNode(ptr, 10);
    traverse_inorder(ptr);
    struct Node *found = search(ptr, 10);
}
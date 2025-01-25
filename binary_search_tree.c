#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

void traverse(struct Node* n){
    if (n == NULL){
        return;
    }
    traverse(n->left);
    printf("%d ", n->key);
    traverse(n->right);
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

int main(){
    struct Node tree = {5, NULL, NULL};
    struct Node *ptr = &tree;

    insertNode(ptr, 10);
    traverse(ptr);

}
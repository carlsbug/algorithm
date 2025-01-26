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

struct Node* searchNode(struct Node* n, int key){
    if (n == NULL){
        return NULL;
    }
    else if (n->key == key){
        return n;
    }
    else if (n->key > key){
        return searchNode(n->left, key);
    }
    else{
        return searchNode(n->right, key);
    }
}

struct Node* findLeastNode(struct Node* n){
    while (n->left!=NULL){
        n = n->left;
    }
    return n;
};

struct Node* insertNode(struct Node* n, int key){
    if (n == NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (key < n->key){
        n->left = insertNode(n->left, key);
        return n;
    }
    else {
        n->right = insertNode(n->right, key);
        return n;
    }
}

struct Node* deleteNode(struct Node* n, int key){
    if (n == NULL){
        return NULL;
    }
    else if(key == n->key){
        if (n->left ==NULL && n->right==NULL){
            free(n);
            return NULL;
        }
        else if(n->left== NULL && n->right != NULL){
            struct Node* temp = n->right;
            free(n);
            return temp;
        }
        else if(n->left != NULL && n->right ==NULL){
            struct Node* temp = n->left;
            free(n);
            return temp;
        }
        else{ // when n has both children, left and right
            struct Node *leastNode;
            leastNode = n->right;
            while(leastNode->left != NULL){
                leastNode = leastNode->left;
            }
            n->key = leastNode->key;
            n->right = deleteNode(n->right, leastNode->key);
            return n;
        }
    }
    else if (n->key > key){
        n->left = deleteNode(n->left, key);
        return n;
    }
    else {
        n->right = deleteNode(n->right, key);
        return n;
    }
}

void freeTree(struct Node* n) {
    if (n == NULL) {
        return;
    }
    freeTree(n->left);
    freeTree(n->right);
    free(n);
}

int main(){
    struct Node* tree = (struct Node*)malloc(sizeof(struct Node));
    tree->key = 55;
    insertNode(tree, 15);
    insertNode(tree, 8);
    insertNode(tree, 3);
    insertNode(tree, 28);
    insertNode(tree, 18);
    insertNode(tree, 45);
    insertNode(tree, 41);
    insertNode(tree, 30);
    insertNode(tree, 38);
    insertNode(tree, 33);
    insertNode(tree, 32);
    insertNode(tree, 36);
    insertNode(tree, 48);
    insertNode(tree, 50);
    insertNode(tree, 60);
    insertNode(tree, 90);
    deleteNode(tree, 28);
    traverse(tree);
    freeTree(tree);
    return 0;
}
#include <stdio.h>

struct Node_4byte{
    int key;
    char content;
    struct Node_4byte *left;
    struct Node_4byte *right;
};

struct Node_8byte{
    int key;
    struct Node_8byte *left;
    char content;
    struct Node_8byte *right;
};

// padding byte size can indeed vary depending on the order of variables in a struct.
int main(){
    struct Node_4byte node_4 = {5};
    struct Node_8byte node_8 = {5};
    printf("---Node 4 byte\n");
    printf("Address of key(int): %p\n", (void*)&node_4.key); // 4byte
    printf("Address of content(char): %p\n", (void*)&node_4.content); // 4 byte 
    printf("Address of left(*node): %p\n", (void*)&node_4.left);
    printf("Address of right(*node): %p\n", (void*)&node_4.right);

    printf("---Node 8 byte\n");
    printf("Address of key(int): %p\n", (void*)&node_8.key); // 8byte 
    printf("Address of left(*node): %p\n", (void*)&node_8.left);
    printf("Address of content(char): %p\n", (void*)&node_8.content); // 8byte 
    printf("Address of right(*node): %p\n", (void*)&node_8.right);

    printf("---Size check by sizeof()\n");
    printf("Size of key: %zu bytes\n", sizeof(&node_8.key));
    printf("Size of content: %zu bytes\n", sizeof(&node_4.content));
    printf("Size of left: %zu bytes\n", sizeof(&node_4.left));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    
}
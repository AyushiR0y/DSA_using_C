// C Program to create a Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the structure of Node
typedef struct Node {

    // Data field
    int data;

    // Pointer to the next node
    struct Node *next;

    // Pointer to the previous node
    struct Node *prev;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    // Initially assigning the next and prev pointers to NULL
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int main() {

    // Create and initialize nodes
    Node *head = createNode(10);
    Node *second = createNode(20);
    Node *third = createNode(30);

    // Linking the nodes
    head->next = second; // This will create: 10 <-> 20
    second->prev = head;
    second->next = third; // This will create: 10 <-> 20 <-> 30
    third->prev = second;

    printf("Doubly Linked List: ");
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
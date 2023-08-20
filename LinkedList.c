#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Node Structure
struct Node
{
    int data;
    struct Node *next;
};

// Loading effect
void loading()
{
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(1);
    }
}

// Length of list
int length(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
// Node Initialization
struct Node *getNode(int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Node Creation
void append(struct Node **head, int data)
{
    struct Node *new_node = getNode(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct Node *temp = malloc(sizeof(struct Node));
    temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Node Insertion
void insertNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("\nLinked List is empty\n");
        sleep(1);
        return;
    }
    int pos, data;
    printf("\nEnter data: ");
    scanf("%d", &data);
    struct Node *new_node = getNode(data);
    while (1)
    {
        printf("\nEnter position: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > length(*head) + 1)
        {
            printf("\nInvalid Position");
            sleep(1);
            system("cls");
            printf("*** INSERT NODE ***\n");
            printf("\nEnter data: %d\n", data);
        }
        else
            break;
    }
    if (pos == 1)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else if (pos == length(*head) + 1)
    {
        append(head, data);
    }
    else
    {
        struct Node *temp = *head;
        for (int i = 1; i <= pos; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("\nInserting");
    loading();
    printf("\nNode inserted successfully");
    sleep(1);
}

// Node deletion
void deleteNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("\nLinked List is empty\n");
        sleep(1);
        return;
    }
    int pos;
    while (1)
    {
        printf("\nEnter position: ");
        scanf("%d", &pos);
        if (pos < 1 || pos > length(*head))
        {
            printf("\nInvalid Position");
            sleep(1);
            system("cls");
            printf("*** DELETE NODE ***\n");
        }
        else
            break;
    }
    struct Node *temp = *head;
    if (pos == 1)
    {
        *head = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else if (pos == length(*head))
    {
        struct Node *prev = temp;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    else
    {
        struct Node *prev = temp;
        for (int i = 1; i <= pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    printf("\nDeleting");
    loading();
    printf("\nNode deleted successfully");
    sleep(1);
}

// Print List
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
        sleep(1);
        return;
    }
    printf("\nItems in the list:");
    while (head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
}

// Driver code
void main()
{
    struct Node *head = NULL;
    int choice = 0, data;
    while (choice != 5)
    {
        system("cls");
        printf("****** LINKED LISTS ******\n\n");
        printf("1. Add Node\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Print List\n");
        printf("5. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("*** ADD NODE ***\n");
            printf("\nEnter data: ");
            scanf("%d", &data);
            append(&head, data);
            printf("\nCreating");
            loading();
            printf("\nNode created successfully\n");
            sleep(1);
            break;
        case 2:
            system("cls");
            printf("*** INSERT NODE ***\n");
            insertNode(&head);
            break;
        case 3:
            system("cls");
            printf("*** DELETE NODE ***\n");
            deleteNode(&head);
            break;
        case 4:
            printList(head);
            sleep(2);
            break;
        case 5:
            printf("\nExiting");
            loading();
            printf("\nExited successfully.\n");
            sleep(1);
            break;
        }
    }
}

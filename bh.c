// C++ program to implement the binary min heap data
// stucture using arrays
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// utility function to swap two values
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* heap, int size, int i)
{
    if (!heap) {
        printf("Invalid Heap!\n");
        return;
    }
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // if we are creating min heap, then we take
    // the smallest element, if we are creating
    // max heap, then we will take the largest element
    int smallest = i;
    if (leftChild < size
        && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < size
        && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    // if the root is not the smallest, we need to swap
    if (smallest != i) {
        swap(heap + i, heap + smallest);
        heapify(heap, size, smallest);
    }
}

// building heap form the whole array
void buildHeap(int* arr, int size)
{
    int start = size / 2 - 1;
    for (int i = start; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

// insert new element
void insert(int* heap, int* size, int element)
{
    if (*size == MAX_SIZE) {
        printf("Heap Overflow!\n");
        return;
    }

    heap[*size] = element;
    (*size)++;

    int i = *size - 1;
    while (i > 0) {
        if (heap[(i - 1) / 2] > heap[i]) {
            swap(heap + (i - 1) / 2, heap + i);
            i = (i - 1) / 2;
        }

        else {
            break;
        }
    }
}

// delete elements
void delete (int* heap, int* size, int index)
{
    if (size == 0) {
        printf("Heap Underflow\n");
        return;
    }

    heap[index] = heap[*size - 1];
    *size = *size - 1;

    heapify(heap, *size, index);
}

// extract the mininmum
int extractMin(int* heap, int* size)
{
    int min = heap[0];

    delete (heap, size, 0);

    return min;
}

// function to print heap
void printHeap(int* heap, int size)
{
    // int lastInternal = size / 2 - 1;
    // int curLevel;
    // int nodeCount;
    // int i = 0;
    // while (i <= lastInternal) {
    //     int curLevel = log2(i + 1);
    //     nodeCount = 0;
    //     while(nodeCount != curLevel) {
    //         printf("%d ", heap[i + nodeCount])
    //     }
    //     print
    // }
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// driver code
int main()
{
    int heap[MAX_SIZE] = { 11 };
    int size = 0;

    buildHeap(heap, size);

    insert(heap, &size, 3);
    insert(heap, &size, 2);
    insert(heap, &size, 1);
    insert(heap, &size, 15);
    insert(heap, &size, 5);
    insert(heap, &size, 4);
    insert(heap, &size, 45);

    printHeap(heap, size);

    return 0;
}
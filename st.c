// C program to demonstrate Segment Tree implementation

#include <stdio.h>

#define MAX_SIZE 1000

int segmentTree[MAX_SIZE];

// Function to build the segment tree
void buildSegmentTree(int arr[], int node, int start,
                      int end)
{
    if (start == end) {
        segmentTree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentTree(arr, 2 * node, start, mid);
    buildSegmentTree(arr, 2 * node + 1, mid + 1, end);
    segmentTree[node]
        = segmentTree[2 * node] + segmentTree[2 * node + 1];
}

// Function to query the segment tree
int query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return 0;
    if (l <= start && end <= r)
        return segmentTree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r)
           + query(2 * node + 1, mid + 1, end, l, r);
}

// Function to update the segment tree
void update(int node, int start, int end, int idx, int val)
{
    if (start == end) {
        segmentTree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    segmentTree[node]
        = segmentTree[2 * node] + segmentTree[2 * node + 1];
}

// Driver code
int main()
{
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    buildSegmentTree(arr, 1, 0, n - 1);
    printf("Sum of elements in range [1, 3] is %d\n",
           query(1, 0, n - 1, 1, 3));
    update(1, 0, n - 1, 2, 10);
    printf("Sum of elements in range [1, 3] after update "
           "is %d\n",
           query(1, 0, n - 1, 1, 3));
    return 0;
}
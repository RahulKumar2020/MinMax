#include <stdio.h>
#include <stdlib.h>


// Helper functions to get parent, left child, and right child indices
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify function
void minHeapify(int heap[], int n, int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < n && heap[l] < heap[smallest])
        smallest = l;
    if (r < n && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

// Max-Heapify function
void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < n && heap[l] > heap[largest])
        largest = l;
    if (r < n && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

// Function to heapify the Min-Max Heap
void heapifyMinMax(int heap[], int n, int i) {
    int level = 0;
    int currentIndex = i;
    
    // Calculate the level of the node
    while (currentIndex > 0) {
        currentIndex = parent(currentIndex);
        level++;
    }
    
    if (level % 2 == 0) {
        // Even level: Min level, apply Min-Heapify
        minHeapify(heap, n, i);
    } else {
        // Odd level: Max level, apply Max-Heapify
        maxHeapify(heap, n, i);
    }
}

// Function to build the Min-Max Heap
void buildMinMaxHeap(int heap[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapifyMinMax(heap, n, i);
    }
}

// Function to print the heap
void printHeap(int heap[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Driver function
int main() {
    int heap[] = {10, 20, 15, 30, 40, 50, 5};
    int n = sizeof(heap) / sizeof(heap[0]);

    // Build the Min-Max Heap
    buildMinMaxHeap(heap, n);

    printf("Heapified Min-Max Heap:\n");
    printHeap(heap, n);

    return 0;
}


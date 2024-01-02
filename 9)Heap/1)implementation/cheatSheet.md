# Heap Data Structure Cheatsheet

## Overview

A heap is a specialized tree-based data structure(Complete Binary tree) that satisfies the heap property. It is commonly used to implement priority queues.

## [Video Tutorial](https://youtu.be/ywx-Onrdx4U?si=nQPXIuH4Ty-VD_zC)

- **Max Heap:** Each parent node is greater than or equal to its children.
- **Min Heap:** Each parent node is less than or equal to its children.

## Operations

### Push (Insert)

#### Element is always pushed at the last then the vector is heapified to maintain the order of heap

#### Time Complexity: O(log(n))

```cpp
void push(vector<int> &heap, int value) {
  heap.push_back(value);
  int i = heap.size() - 1;
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[i] > heap[parent]) {
      swap(heap[i], heap[parent]);
      i = parent;
    } else {
      break;
    }
  }
}


```

### Pop (Delete)

#### Element is always deleted from the root then the vector is heapified to maintain the order of heap

#### Time Complexity: O(log(n))

```cpp
void pop(vector<int> &heap) {
  heap[0] = heap.back();
  heap.pop_back();
  int i = 0;
  while (i < heap.size()) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild >= heap.size()) {
      break;
    }
    int maxChild = leftChild;
    if (rightChild < heap.size() && heap[rightChild] > heap[leftChild]) {
      maxChild = rightChild;
    }
    if (heap[i] < heap[maxChild]) {
      swap(heap[i], heap[maxChild]);
      i = maxChild;
    } else {
      break;
    }
  }
}

```

### Top (Peek)

```cpp
int top(vector<int> &heap) {
  return heap[0];
}

```

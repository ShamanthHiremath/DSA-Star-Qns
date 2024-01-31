#include <bits/stdc++.h> 

using namespace std;

void heapify(vector<int> &arr, int index) {
    int smallest = index;
    int leftnode = 2 * index + 1;
    int rightnode = 2 * index + 2;

    if (leftnode < arr.size() && arr[leftnode] < arr[smallest]) {
        smallest = leftnode;
    }

    if (rightnode < arr.size() && arr[rightnode] < arr[smallest]) {
        smallest = rightnode;
    }

    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapify(arr, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    // Start heapify from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i);
    }
    return arr;
}

void heapifyRec(int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // If left child is larger than root
    if (left < heap.size() && heap[left] > heap[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < heap.size() && heap[right] > heap[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != index)
    {
        swap(heap[index], heap[largest]);
        // Recursively heapify the affected subtree
        heapify(largest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();
    // Start heapify from the last non-leaf node
    for (int i = n / 2 ; i > 0; i--) {
        heapify(arr, i);
    }
    return arr;
}

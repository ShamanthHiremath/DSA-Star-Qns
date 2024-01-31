void heapSort()
{
    int size = heap.size() - 1;
    while (size >= 0)
    {
        // swap first and last element
        swap(heap[0], heap[size]);
        // decrease size
        size--;
        // heapify
        heapify(size);
    }
}

void heapify(int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        // if the the current node is smaller than its left node
        if (left < heap.size() && heap[left] > heap[index])
        {
            swap(heap[index], heap[left]);
            index = left;
        }
        // if the the current node is smaller than its right node
        if (right < heap.size() && heap[right] > heap[index])
        {
            swap(heap[index], heap[right]);
            index = right;
        }
        else
        {
            return; // No more swaps needed, heap property satisfied
        }
    }
}
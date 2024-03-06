
class Solution{
public:
    void heapify(int index, vector<int>& heap) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index; // Assume the current index is the largest

            // Compare with left child
            if (left < size && heap[left] > heap[largest])
                largest = left;
            // Compare with right child
            if (right < size && heap[right] > heap[largest])
                largest = right;

            // If the largest is not the current index, swap and continue heapifying
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                return; // No more swaps needed, heap property satisfied
            }
        }
    }
        
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // Merge the elements of a and b into a new heap
        vector<int> heap(a.begin(), a.end());
        heap.insert(heap.end(), b.begin(), b.end());
        
        // Heapify the merged heap
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapify(i, heap);
        }
        
        return heap;
    }
};
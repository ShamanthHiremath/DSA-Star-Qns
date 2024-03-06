int kthSmallest(int arr[], int l, int r, int k) {
    //max heap
    priority_queue<int>heap;
    
    //insert the first k elements
    for(int i=0; i<k ;i++ ){
        heap.push(arr[i]);
    }
    
    //insert the element only if it is smaller than the top of the heap
    for(int i=k; i<=r ;i++ ){
        if(arr[i]<heap.top()){
            heap.pop();
            heap.push(arr[i]);
        }
    }
    return heap.top();
}
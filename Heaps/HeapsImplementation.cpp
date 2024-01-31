#include<bits/stdc++.h>

// #include<iostream>
using namespace std;



//If the node is at i th index, then
//the left child is at 2*i th index
//the right child  is at ( 2*i )+1 th index
//parent is at i/2 th index;
class maxHeap{
    private:
        vector<int>heap;
    public:
        void insert(int num){
            //Push the num in the last index
            heap.push_back(num);
            int index=heap.size()-1;
            while(index>0){
                int parent=index/2 ;
                if(heap[parent]<heap[index]){
                    //swap the parent node with the index
                    swap(heap[parent], heap[index]);
                    //make index=parent and repeat untill u find the root
                    index=parent;
                }
                else{
                    return;
                }
            }
        }

        int deleteNode(){
            if(heap.empty()){
                throw runtime_error("Heap Empty");
            }
            //store to return
            int maxfront= heap[0];
            //input the last node in the first node
            heap[0]=heap.back();
            //delete last node
            heap.pop_back();
            //call helper fn for root/0th index
            heapify(0) ;
            // heapifyRec(0);
            return maxfront;
        }

        void heapifyRec(int index){
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            // If left child is larger than root
            if (left < heap.size() && heap[left] > heap[largest]){
                largest = left;
            }

            // If right child is larger than largest so far
            if (right < heap.size() && heap[right] > heap[largest]){
                largest = right;
            }

            // If largest is not root
            if (largest != index){
                swap(heap[index], heap[largest]);
                // Recursively heapify the affected subtree
                heapify(largest);
            }

        }

        
        void heapify(int index) {
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                //if the the current node is smaller than its left node 
                if (left < heap.size() && heap[left] > heap[index]){
                    swap(heap[index], heap[left]);
                    index = left;
                }
                //if the the current node is smaller than its right node 
                if (right < heap.size() && heap[right] > heap[index]){
                    swap(heap[index], heap[right]);
                    index = right;
                }
                else {
                    return ; // No more swaps needed, heap property satisfied
                }
            }

        }

        void heapSort(){
            int size=heap.size()-1;
            while(size>=0){
                //swap first and last element
                swap(heap[0], heap[size]);
                //decrease size
                size--;
                //heapify
                heapify(size);
            }
        }

        void printHeap(){
            for(auto i: heap){
                cout<<i<<"  ";
            }
        }

};

int main(){

    maxHeap myHeap;
    myHeap.insert(20);
    myHeap.insert(80);
    myHeap.insert(100);
    myHeap.insert(70);
    myHeap.insert(90);
    // myHeap.insert(110);

    myHeap.printHeap();
    // myHeap.heapSort();
    cout<<endl<<myHeap.deleteNode()<<endl;
    cout<<myHeap.deleteNode()<<endl;
    cout<<myHeap.deleteNode()<<endl;


    myHeap.printHeap();
 return 0;
}
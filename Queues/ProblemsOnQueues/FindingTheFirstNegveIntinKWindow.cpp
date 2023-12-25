/*
Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6

Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 */

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {


    deque<long long> dq;
    vector<long long>ans;
    //Processing the First Window of Size K
    //If an element is negative, its index is pushed to the back of the deque dq. This ensures that the
    //deque maintains the indices of negative elements in the current window.
    for(int i=0; i<K; i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    //  checks if the deque is not empty. If it is not, the first negative element's value
    //  (at the front of the deque) is added to the result vector ans.
    //  If the deque is empty, it means there are no negative elements in the current window,
    //  so 0 is added to ans.
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    for(int i=K; i<N; i++){
        //checks if the deque is not empty and if the front index of the deque is beyond the current
        //window (more than K elements away). If true, it means the first negative element has moved out
        //of the window, so it is popped from the front of the deque.
        if(!dq.empty() && i-dq.front()>=K){
            dq.pop_front();
        }
        if(A[i]<0){
            dq.push_back(i);
        }
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
    }
    return ans;
}
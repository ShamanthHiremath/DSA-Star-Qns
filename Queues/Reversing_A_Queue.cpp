class Solution
{
    public:
    // Base case is stop when the queue is empty that is when u reach the last element to enqueue 
    // Dequeue the front element of the queue.
    // Recursively reverse the remaining queue.
    // Enqueue the front element that was dequeued in step 1.
    void solve(queue<int>& q){
        if(q.empty()){
            return;
        }
        int element=q.front();
        q.pop();
        solve(q);
        q.push(element);
    }
    queue<int> rev(queue<int> q)
    {
        //APPROACH 1 is to use a stack and push dequeued elements
        //later pop the elements from stack and enqueue itin the same queue
        // stack<int>s;
        // while(!q.empty()){
        //     s.push(q.front());
        //     q.pop();
        // }
        // while(!s.empty()){
        //     q.push(s.top());
        //     s.pop();
        // }
        // return q;
        solve(q);
        return q;
    }
};
class Solution
{
    public:
    //1 2 3 4 5 6 7 8
    // s 1 2 3 4 top
    // q is 5 6 7 8
    // 
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>s;
        int i=0;
        //remove k elements store it in a stack
        while(i!=k){
            s.push(q.front());
            q.pop();
            i++;
        }
        //enqueue the elements to the q from the stack
        i=0;
        while(i!=k){
            q.push(s.top());
            s.pop();
            i++;
        }
        //now the remaining n-k elements should be enqueued at the back of reversed part
        i=0;
        while(i!=q.size()-k){
            q.push(q.front());
            q.pop();
            i++;
        }
        return q;
    }
};
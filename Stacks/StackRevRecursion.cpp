void insertAtBottom(stack<int>& stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int storeprevelement=stack.top();
    stack.pop();
    insertAtBottom(stack, x);
    stack.push(storeprevelement);
}

void reverse(stack<int> &stack, int top){

    if(stack.empty()){
        return;
    }
    //RECURSION SAYS DO ONE JOB HANDLE THE REST
    //Just store the top element and assume that the rest of the stack is reversed
    int storetop=stack.top();
    stack.pop();
    //assumed
    reverse(stack, top);
    //insert stored top element at the bottom
    insertAtBottom(stack, storetop);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()|| stack.size()==1){
        return;
    }
    reverse(stack, stack.top());
}
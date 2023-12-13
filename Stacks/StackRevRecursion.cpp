void insertt(stack<int>& stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int storeprevelement=stack.top();
    stack.pop();
    insertt(stack, x);
    stack.push(storeprevelement);
}

void reverse(stack<int> &stack, int top){
    if(stack.empty()){
        return;
    }
    int storetop=stack.top();
    stack.pop();
    reverse(stack, top);
    insertt(stack, storetop);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()|| stack.size()==1){
        return;
    }
    reverse(stack, stack.top());
}
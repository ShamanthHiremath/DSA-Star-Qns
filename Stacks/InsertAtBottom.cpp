#include <bits/stdc++.h> 
void insertt(stack<int>& myStack, int x, int size){
    if(size==-1){
        myStack.push(x);
        return;
    }
    int storeprevelement=myStack.top();
    myStack.pop();
    insertt(myStack, x, size-1);
    myStack.push(storeprevelement);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int size=myStack.size()-1;
    insertt(myStack,x,size);
    return myStack;
}
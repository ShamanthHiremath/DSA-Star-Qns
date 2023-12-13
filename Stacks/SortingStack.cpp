#include <bits/stdc++.h>
//insert at the place where the top element is lesser than the insertnumber
void insertSort(stack<int> &stack, int num){
	if(stack.empty() || (!stack.empty() && stack.top() < num)){
		stack.push(num);
		return;
	}
	int storetop=stack.top();
	stack.pop();
	insertSort(stack, num);
	stack.push(storetop);
}
void popptop(stack<int> &stack){
// pop the top elements untill it becomes empty
	if(stack.empty()){
		return;
	}
    //take the top element for insertion
	int n= stack.top();
	stack.pop();
	popptop(stack);
    //whem it becomes empty insert the element at the top in a place where there is a number lesser than the top(n) 
	insertSort(stack, n);
}

void sortStack(stack<int> &stack)
{
    //pop the topelements
	popptop(stack);
}
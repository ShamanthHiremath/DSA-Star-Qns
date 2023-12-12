#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
   if(N==0){
      inputStack.pop();
      // cout<<"EMPTYSTACK";
      return;
   } 
   int end=0;
   if((N+1)%2==0){
      end=(N+1)/2;
   }
   else{
      end=(N+1)/2+1;
   }
   vector<int>arr;
   for(int i=1; i<end; i++){
      arr.push_back(inputStack.top());
      inputStack.pop();
   }
   inputStack.pop();
   for(int i=end-2; i>=0; i--){
      inputStack.push(arr[i]);
   }
}
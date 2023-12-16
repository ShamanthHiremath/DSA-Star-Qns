#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    if(n==1)return {-1};
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        int store=arr[i];
        //pop the element greater than the current element under scan
        while(st.top()>=arr[i]){
            st.pop();
        }
        //store the top element in array
        arr[i]=st.top();
        st.push(store);
    
    }
    return arr;
}
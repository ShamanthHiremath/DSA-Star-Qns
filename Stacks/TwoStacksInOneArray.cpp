#include <bits/stdc++.h> 
class TwoStack {
    int top1;
    int top2;//size would be enough
    //int total=top1+top2;
    int size;
    int *arr;


public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
        top1=-1;
        top2=s;
        //total=-1;
        arr=new int[s];


    }
    
    // Push in stack 1.
    void push1(int num) {

        if(/*top1<size &&top1<top2&&*/ (top1+1)<top2){
            top1++;
            arr[top1]=num;
        }
        // else{
        //     cout<<"OVERFLOW";
        // }
    }

    // Push in stack 2.
    void push2(int num) {
        if(/*top2>0 && top2>top1 &&*/(top1+1)<top2){
            top2--;
            //total++;
            arr[top2]=num;
        }
        // else{
        //     cout<<"OVERFLOW";
        // }
    }
//Pop in stack1
    int pop1() {
        if(top1>=0){
            // int ans= arr[top1];
            // top1--;
            // return ans;
            return  arr[top1--];
        }
        else{
            return -1;
        }
    }
//Pop in stack2
    int pop2() {
        if(top2<size){
            // int ans= arr[top2];
            // top2++;
            // return ans;
            return arr[top2++];

        }
        else{
            return -1;
        }

    }
};

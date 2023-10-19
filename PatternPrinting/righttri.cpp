//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
   
    while(i<=n){
        int j=0;
        while(i!=j){
            cout<<i;
            j++;
        }
        i++;
        cout<<endl;
    }



 return 0;
}
/*
use count septly
1
2 3
4 5 6
7 8 9 10

use i for printing
1
22
333
4444
55555

use? i-j+1?
1
21
321
4321
54321

i+j-1
123
234
345

AAAA
BBBB
CCCC
DDDD



ABC
DEF
GHI

*/
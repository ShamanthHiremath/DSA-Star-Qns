//#include<bits/stdc++.h>

#include<iostream>
using namespace std;

int floatsqrt(int n){
    int s=0,e=n,mid=s+(e-s)/2, ans=0;
    while(s<=e){
        if(mid*mid==n){
            return mid;
        }
        if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;

}
double morePrecision(int n, int precision, int integersoln){
    double factor=1;ot
    
    double ans= integersoln;
    for(int i=0;i<precision;i++){
        factor/=10;
        for(double j=ans; j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;


}

int main(){
    int n;
    cin>>n;
    int integersoln=floatsqrt(n);
    cout<<floatsqrt(n);
    cout<<morePrecision(n, 4, integersoln);
 return 0;
}
#include<bits/stdc++.h>
using namespace std;


//USING MEMOISATION/ TOP DOWN APPROACH
int fibo(int n, vector<int>&dp){
       if(n==0||n==1){
              return n;
       }
       if(dp[n]!=-1){
              return dp[n];
       }
       dp[n]=fibo(n-1, dp)+ fibo(n-2, dp);
       return dp[n];
}


int main()
{
       int n;
       cin>> n;
       vector<int>dp(n+1, -1);
       cout<<fibo(n, dp);
}


//TABULATION APPROACH/ BOTTOM UP APPROACH
int main()
{
       int n;
       cin>> n;
       vector<int>dp(n+1);
       //form base case
       dp[0]=0;
       dp[1]=1;
       for(int i=2; i<=n; i++){
              dp[i]=dp[i-1]+dp[i-2];
       }
       cout<< dp[n];
}

//SPACE OPTIMISATION
int main()
{
       int n;
       cin>> n;
       
       int prev=0;
       int next=1;
       if(n==0||n==1){
              cout <<n;
              return 0;
       }
       int current;
       for(int i=2; i<=n; i++){
              current=prev+next;
              prev=next;
              next=current;
       }
       cout<<current;
       return 0;
}                    
class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n,true);
        if(n<3)return 0;
        int count=0;
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                for(int j=2*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        return count;
        
    }
};
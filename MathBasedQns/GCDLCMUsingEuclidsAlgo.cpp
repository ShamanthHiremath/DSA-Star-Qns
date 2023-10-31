class Solution {
public:
    vector<int> GcdLcm(int n, int a, int b) {
        vector<int>ans(n);
        //Works on the properties of GCD();
        //GCD(a,b)=GCD(a-b,b)=GCD(a,a-b)
        //GCD(a%b,b)=GCD(a,a%b)
        // untill either a or b becomes 0
        //GCD=x if GCD(0,x) or GCD(x,0)
        //LCM*GCD= a*b
        int GCD=0, LCM=0;
        int num1=a, num2=b;
        if(a==0) GCD=b;
        if(b==0) GCD=a;

        while(a!=b){
            if(a>b){
                a=a-b;
            }
            else{
                b=b-a;
            }
        }
        GCD=a; //GCD=b
        LCM=(num1*num2)/GCD;
        ans.push_back(GCD);
        ans.push_back(LCM);
        return ans;
        
    }
};
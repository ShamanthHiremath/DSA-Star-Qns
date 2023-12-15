class Solution {
    int add(int a, int b){
        if(abs(a)==abs(b))return 0;
        else{
            if(abs(a)>abs(b)){
                return a;
            }
            else{
                return b;
            }
        }
    }
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int>s;
        for(int i=0; i<N; i++){
            //if stack is empty or the stored top value is -ve or the asteroids[i] is +ve
            //add it to the stack
            if(s.empty() || s.top()<0 || asteroids[i]>0){
                s.push(asteroids[i]);
            }
            //any other case, decider edge cases
            else{
                //if the top value is +ve and the abs asteroids[i] is greater than top
                //remove the top untill the stck gets empty or untill the top value is larger or equal or -ve  
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i])){
                    s.pop();
                }
                // if eother the stack is empty or it has a -ve value push asteroids[i]
                if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                }
                //if the value of top and asteroids[i] is same destroy them
                else if (s.top()==abs(asteroids[i])){
                    s.pop();
                }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
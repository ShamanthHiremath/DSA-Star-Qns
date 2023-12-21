class SpecialStack {
    stack<int>s;
    int min=INT_MAX;
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            min=data;
        }
        else{
            if(data<min){
                int val=2*data-min;
                min=data;
                s.push(val);
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()){
            // cout<<"UNDERFLOW";
            return;
        }
        else{
            if(s.top()<min){
                int val=2*min-s.top();
                // return min;
                s.pop();
                min=val;
            }
            else{
                s.pop();
            }
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        else{
            if(s.top()<min){
                return min;
            }
            else{
                return s.top();
            }
        }
        // Implement the top() function.
    }

    int getMin() {
        if(s.empty())return -1;
        return min;
        // Implement the getMin() function.
    }  
};
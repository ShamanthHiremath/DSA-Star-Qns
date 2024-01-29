class MyQueue {
    private:
    stack<int> insertStack;
    stack<int> deleteStack;
public:
    MyQueue() {
        //NOT NEEDED NECCESARILY
    }
    
    void push(int x) {
        if(this->deleteStack.empty()){
            this->insertStack.push(x);
        }
        else{
            //Transfer elements from DELETE STACK to INSERT STACK
            while(!this->deleteStack.empty()){
                this->insertStack.push(this->deleteStack.top());
                this->deleteStack.pop();
            }
            this->insertStack.push(x);
        }
    }
    
    int pop() {
        if(this->insertStack.empty() && this->deleteStack.empty()){
            return -1;
        }
        if(this->insertStack.empty()){
            int val=this->deleteStack.top();
            this->deleteStack.pop();
            return val;
        }
        if(this->deleteStack.empty()){
            //Transfer elements from INSERT STACK to DELETE STACK  
            while(!this->insertStack.empty()){
                this->deleteStack.push(this->insertStack.top());
                this->insertStack.pop();
            }
        }
        int val=this->deleteStack.top();
        this->deleteStack.pop();
        return val;
        
    }
    
    int peek() {
        // if(this->insertStack.empty() && this->deleteStack.empty()){
        //     return -1;
        // }
        if(insertStack.empty()){
            return deleteStack.top();
            //deleteStack.pop();
            // return val;
        }
        if(this->deleteStack.empty()){
            //Transfer elements from INSERT STACK to DELETE STACK  
            while(!this->insertStack.empty()){
                this->deleteStack.push(this->insertStack.top());
                this->insertStack.pop();
            }
        }
        int val=this->deleteStack.top();
        // deleteStack.pop();
        return val;
    }
    
    bool empty() {
        if(this->insertStack.empty() && this->deleteStack.empty()){
            return true;
        }
        return false;
        
    }
};
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s;
    stack<int>ss;
    
    MinStack() {
        
    }
    
    void push(int val) {
        
        s.push(val);
        
        if(ss.empty())
        {
            ss.push(val);    
        }
        else
        {
            if(ss.top() >= val)
                ss.push(val);
        }
        
       
    }
    
    void pop() {
        
        if(s.empty())
            return;
        
        if(!ss.empty() and s.top()==ss.top())
            ss.pop();
      
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
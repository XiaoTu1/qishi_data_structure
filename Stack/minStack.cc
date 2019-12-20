class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (!minS.empty() && x > minS.top()) {
            minS.push(minS.top());
        } else {
            minS.push(x);
        }
        
        S.push(x);
    }
    
    void pop() {
        minS.pop();
        S.pop();
    }
    
    int top() {
        return S.top();    
    }
    
    int getMin() {
        return minS.top();    
    }

private:
    stack<int> S, minS;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    vector<int> stack;
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        int n = stack.size();
        return stack[n-1];
    }
    
    int getMin() {
        int minElement = INT_MAX;
        for(auto x : stack){
            if(x < minElement) minElement = x;
        }
        return minElement;
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
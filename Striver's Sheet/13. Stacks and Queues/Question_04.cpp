class MyQueue {
public:
    stack<int> inp;
    stack<int> out;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(out.empty()){
            int n = inp.size();
            for(int i = 0; i < n; i++){
                out.push(inp.top());
                inp.pop();
            }
        }
        int val = out.top();
        out.pop();
        return val;
    }
    
    int peek() {
        if(out.empty()){
            int n = inp.size();
            for(int i = 0; i < n; i++){
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return inp.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
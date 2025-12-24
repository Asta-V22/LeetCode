class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {  
    }
    
    void push(int x) {
        int s1 = st1.size();
        for(int i=0; i<s1; i++){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        for(int i=0;i<s1;i++){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int val = st1.top();
        st1.pop();
        return val;
    }

    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
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
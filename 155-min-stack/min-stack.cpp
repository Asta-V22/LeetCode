class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(long long val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val < mini){
                st.push(2LL*val - mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini){
            mini = 2LL*mini - x;
        }
    }

    long long top() {
        if(st.empty()) return -1;

        long long x = st.top();
        return (x < mini) ? mini : x;
    }

    long long getMin() {
        return mini;
    }
};

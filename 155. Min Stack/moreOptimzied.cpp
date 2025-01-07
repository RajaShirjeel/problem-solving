class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = static_cast<long long>(value);
        if (st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if (val > mini){
                st.push(val);
            }
            else{
                st.push(2 * val - mini);
                mini = val;
            }
        }

    }
    
    void pop() {
        if (st.empty()) return;
        long long val = st.top();
        st.pop();

        if (val < mini){
            mini = 2 * mini - val;
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        long long val = st.top();
        if (val < mini){
            return (mini);
        }
        return (val);
    }
    
    int getMin() {
        return (mini);
    }
};
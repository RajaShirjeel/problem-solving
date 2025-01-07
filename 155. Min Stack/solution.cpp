class MinStack {
public:
    stack<pair<int, int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()){
            st.push({val, val});
        }
        else{
            st.push({val, min(st.top().second, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

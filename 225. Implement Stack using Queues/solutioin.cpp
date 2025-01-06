class MyStack {
public:
    queue<int>st;

    MyStack() {
    }
    
    void push(int x) {
        st.push(x);
        for (int i = 1; i < st.size(); i++){
            int val = st.front();
            st.pop();
            st.push(val);
        }
    }
    
    int pop() {
        int val = st.front();
        st.pop();
        return val;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.size() == 0 ? true: false;
    }
};

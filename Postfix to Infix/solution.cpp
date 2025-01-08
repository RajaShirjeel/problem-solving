class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        int n = s.length();
        stack<string>st;
        
        for (int i = 0; i < n; i++){
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string t(1, s[i]);
                st.push(t);
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                string res = '(' + t2 + s[i] + t1 + ')';
                st.push(res);
                
            }
        }
        
        return st.top();
    }
};
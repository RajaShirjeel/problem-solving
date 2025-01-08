class Solution {
  public:
    string preToPost(string s) {
        int n = s.length();
        stack<string>st;
        
        for (int i = n-1; i >= 0; i--){
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
                string t(1, s[i]);
                st.push(t);
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                string res = t1 + t2 + s[i];
                st.push(res);
                
            }
        }
        
        return st.top();
    }
};
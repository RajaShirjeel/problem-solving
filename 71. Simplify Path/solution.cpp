class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        for (int i = 0; i < path.length(); i++){
            if (path[i] == '/'){
                continue;
            }

            string temp = "";
            while (i < path.length() && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if (temp == "."){
                continue;
            }

            else if (temp == ".."){
                if (!st.empty()){
                    st.pop();
                }
            }

            else{
                st.push(temp);
            }

        }

        string res;
        while (!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        if (res.length() == 0){
            return "/";
        }

        return res;
        
    }
};
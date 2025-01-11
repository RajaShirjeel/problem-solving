class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        
        stack<int>st1, st2;
        vector<int>count(n);
        vector<int>res;
        
        for (int i = n - 1; i >= 0; i--){
            while (!st2.empty() && arr[i] <= st2.top()){
                int temp = st2.top();
                st2.pop();
                st1.push(temp);
            }
            
            while (!st1.empty() && arr[i] >= st1.top()){
                int temp = st1.top();
                st1.pop();
                st2.push(temp);
            }
            
            count[i] = st1.empty() ? 0: st1.size();
            st1.push(arr[i]);
        }
        
        for (auto x: indices){
            res.push_back(count[x]);
        }
        
        return res;
       
    }

};
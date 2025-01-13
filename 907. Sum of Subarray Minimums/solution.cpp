class Solution {
public:
    vector<int>findNSE(vector<int>arr, int n){
        stack<int>st;
        vector<int>nse(n);

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n: st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int>findPSEE(vector<int>arr, int n){
        stack<int>st;
        vector<int>psee(n);

        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            psee[i] = st.empty() ? -1: st.top();
            st.push(i);
        }

        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse;
        vector<int>psee;
        int mod = (int)(1e9 + 7);

        nse = findNSE(arr, n);
        psee = findPSEE(arr, n);

        
        int total = 0;
        for (int i = 0; i < n; i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + (1LL * right * left * arr[i]) % mod) % mod;
        }

        return total;

    }
};
class Solution {
public:
    vector<int>findNSE(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>nse(n);

        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        
        return nse;

    }

    vector<int>findPSEE(vector<int>&arr){
        int n = arr.size();
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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>nse;
        vector<int>psee;
        long long total = 0;
       

        nse = findNSE(arr);
        psee = findPSEE(arr);

        for (int i = 0; i < arr.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            total = ((total + right * left * 1LL * arr[i]));

        }

        return total;

        
    }

    vector<int>findNGE(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>nge(n);

    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        nge[i] = st.empty() ? n: st.top();
        st.push(i);
    }
    
    return nge;

    }

    vector<int>findPGEE(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int>pgee(n);

        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }

            pgee[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        
        return pgee;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>nge;
        vector<int>pgee;
        long long total = 0;

        nge = findNGE(arr);
        pgee = findPGEE(arr);

        for (int i = 0; i < arr.size(); i++){
            int left = i - pgee[i];
            int right = nge[i] - i;

            total = ((total + right * left * 1LL * arr[i]));

        }

        return total;

        
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minTotal = sumSubarrayMins(nums);
        long long maxTotal = sumSubarrayMaxs(nums);
        return (long long)(maxTotal - minTotal);

    }
};
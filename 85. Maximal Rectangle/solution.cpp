class Solution {
public:

    vector<int>findPSE(vector<int>&arr){
        int n = arr.size();
        vector<int>pse(n);
        stack<int>st;

        for (int i = 0; i < n; i++){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int>findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;

        for (int i = n-1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        vector<int>nse;
        vector<int>pse;

        nse = findNSE(heights);
        pse = findPSE(heights);

        for (int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = (nse[i] - i) - 1;
            int area = heights[i] * (left + right);
            maxi = max(area, maxi);
        }

        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int largest = 0;

        vector<vector<int>>prefixCnt(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++){
            int count = 0;
            for (int i = 0; i < n; i++){
                count += (matrix[i][j] - '0');
                if (matrix[i][j] == '0') count = 0;
                prefixCnt[i][j] = count;
            }
        }

        for (int i = 0; i < n; i++){
            largest = max(largest, largestRectangleArea(prefixCnt[i]));
        }
        return largest;

    }
};
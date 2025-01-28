class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int numZeros = 0;
        int maxi = 0;

        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0) numZeros++;

            if (numZeros > k){
                if (nums[left] == 0) numZeros--;
                left++;
            }

            if (numZeros <= k){
                int windowSize = (right - left) + 1;
                maxi = max(maxi, windowSize);
            }

        }

        return maxi;

    }
};
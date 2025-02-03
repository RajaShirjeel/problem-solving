class Solution {
public:

    int helper(vector<int>nums, int k){
        if (k < 0){
            return 0;
        }

        int left = 0;
        int cnt = 0;
        int odd = 0;

        for (int right = 0; right < nums.size(); right++){
            if (nums[right] % 2 != 0){
                odd ++;
            }

            while (odd > k){
                if (nums[left] % 2 != 0){
                    odd--;
                }
                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
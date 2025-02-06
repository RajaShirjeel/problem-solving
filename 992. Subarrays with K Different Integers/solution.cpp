class Solution {
public:

    int helper(vector<int>nums, int k){
        unordered_map<int, int>m;
        int left = 0;
        int cnt = 0;
        for (int right = 0; right < nums.size(); right++){
            m[nums[right]]++;

            while (m.size() > k){
                m[nums[left]]--;
                if (m[nums[left]] == 0) m.erase(nums[left]);
                left++;
            }

            cnt += right + 1 - left;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
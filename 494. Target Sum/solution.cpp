class Solution {
public:

    void solve(vector<int>&nums, int target, int &count, int index, int currSum){
        if (index == nums.size()){
            if (currSum == target){
                count++;
            }
            return;
        }

        solve(nums, target, count, index + 1, currSum + nums[index]);
        solve(nums, target, count, index + 1, currSum - nums[index]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(nums, target, count, 0, 0);
        return count;

    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        int currSum;
        for (int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size()-1;
            while (j < k && k > j){
                int currSum = nums[i] + nums[j] + nums[k];
                if (currSum == target) return currSum;
                if (abs(currSum - target) < abs(closestSum - target)){
                    closestSum = currSum;
                }
                if (currSum > target){
                    k--;
                }
                else if (currSum < target) {
                    j++;
                }

            }
        }
    
        return closestSum;
    }
};
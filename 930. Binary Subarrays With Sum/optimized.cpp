class Solution {
public:

    int getLessOrEqual(vector<int>nums, int goal){
        if (goal < 0){
            return 0;
        }

        int left = 0;
        int cnt = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right ++){
            sum += nums[right];

            while (sum > goal){
                sum -= nums[left];
                left++;
            }

            cnt += (right - left + 1);

        }

        return cnt;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return getLessOrEqual(nums, goal) - getLessOrEqual(nums, goal - 1);
    }
};
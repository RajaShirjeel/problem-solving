class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>m;
        int totalSubarrays = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];

            if (sum == goal){
                totalSubarrays++;
            }

            if (m.find(sum - goal) != m.end()){
                totalSubarrays += m[sum - goal];
            }

            m[sum]++;
        }

        return totalSubarrays;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n){
            long long correctIndex = static_cast<long long>(nums[i]) - 1;
            if (nums[i] > 0 && nums[i] <= n && nums[correctIndex] != nums[i]){
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            }
            else {
                i++;
            }
        }

        for (long long i = 0; i < n; i++){
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;

    }
};
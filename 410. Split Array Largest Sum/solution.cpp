class Solution {
    public:
    
        int getSplits(vector<int>nums, int maxSum){
            int arr = 1;
            int sum = 0;
    
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] + sum > maxSum){
                    arr++;
                    sum = nums[i];
                }
                else{
                    sum += nums[i];
                }
            }
    
            return arr;
        }
    
        int splitArray(vector<int>& nums, int k) {
            int sum = 0;
            int maxi = INT_MIN;
    
            for (int i = 0; i < nums.size(); i++){
                sum += nums[i];
                maxi = max(maxi, nums[i]);
            }
    
            int low = maxi;
            int high = sum;
    
            while (low <= high){
                int mid = ((low + high) >> 1);
                int splits = getSplits(nums, mid);
    
                if(splits <= k){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
    
            return low;
        }
    };
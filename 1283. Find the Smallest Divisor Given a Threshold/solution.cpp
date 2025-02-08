class Solution {
public:

    int getSum(vector<int>nums, int divi){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            int res = ceil((double) nums[i] / (double) divi);
            sum += res;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());

        int low = 1;
        int high = maxi;
        int ans = INT_MAX;
        while (low <= high){
            int mid = (low + high) / 2;
            int sum = getSum(nums, mid);
        
            if (sum <= threshold){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
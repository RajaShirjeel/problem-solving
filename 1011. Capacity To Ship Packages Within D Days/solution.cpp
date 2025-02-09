class Solution {
public:

    int getDays(vector<int>nums, int weight){
        int totalWeight = 0;
        int days = 0;
        for (int i = 0; i < nums.size(); i++){
            if (totalWeight + nums[i] == weight){
                days++;
                totalWeight = 0;
            }
            else if (totalWeight + nums[i] < weight){
                totalWeight += nums[i];
            }
            else {
                days++;
                totalWeight = 0;
                totalWeight += nums[i];
            }

        }
        if (totalWeight > 0) days ++;
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        for (int i = 0; i < weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }

        int sum = 0;
        for (int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }

        int low = maxi;
        int high = sum;
        int ans;

        while (low <= high){
            int mid = ((low + high) >> 1);
            if (getDays(weights, mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }

        return ans;
    }
};
class Solution {
public:

    int getNumberOfBouquets(vector<int>arr, int day, int k){
        int flowers = 0;
        int boq = 0;

        for (int i = 0; i < arr.size(); i++){

            if (arr[i] - day <= 0){
                flowers++;
            }
            if (flowers == k){
                boq++;
                flowers = 0;
            }
            if (arr[i] - day > 0){
                flowers = 0;
            }
        }

        return boq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if (static_cast<long long>(m) * static_cast<long long>(k) > bloomDay.size()){
            return -1;
        }

        int mini = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
        }
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++){
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;
        int ans;

        while (low <= high){
            int mid = ((low + high ) >> 1);

            if (getNumberOfBouquets(bloomDay, mid, k) >= m){
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
class Solution {
public:

    long long getHours(vector<int>piles, int speed){
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++){
            if (piles[i] == speed){
                hours += 1;
            }
            else{
                hours += ceil(static_cast<double>(piles[i]) / static_cast<double>(speed));
            }
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        int ans;
        for (int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        int low = 1;
        int high = maxi;

        while (low <= high){
            int mid = ((low + high) >> 1);
            long long hoursTaken = getHours(piles, mid);
            if (hoursTaken <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
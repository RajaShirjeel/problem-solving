class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;
        int rSum = 0;
        int right = cardPoints.size() -1;
        int ans = 0;

        for (int i = 0; i < k; i++){
            lSum += cardPoints[i];
        }

        ans = max(ans, lSum);

        for (int i = k-1; i >= 0; i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[right];
            right--;
            ans = max(ans, lSum + rSum);
        }

        return ans;


    }
};
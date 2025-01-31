class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int maxFreq = 0;
        int left = 0;
        vector<int>m(26, 0);

        for (int right = 0; right < s.length(); right++){
            m[s[right] - 'A']++;
            maxFreq = max(maxFreq, m[s[right] - 'A']);

            if ((right - left + 1) - maxFreq > k){
                m[s[left]- 'A']--;
                left ++;
            }   

            if ((right - left + 1) - maxFreq <= k){
                maxi = max(maxi, right - left + 1);
            }

        }

        return maxi;
    }
}; 
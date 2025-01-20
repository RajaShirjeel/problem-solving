class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        unordered_map<char, int>freqMap;

        for (int right = 0; right < s.length(); right++){
            freqMap[s[right]]++;
            while (freqMap[s[right]] > 1){
                freqMap[s[left]]--;
                left ++;
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
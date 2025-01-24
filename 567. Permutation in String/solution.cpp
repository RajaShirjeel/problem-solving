class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq_s1(26, 0);
        vector<int>freq_s2(26, 0);

        int left = 0;

        for (char c: s1){
            freq_s1[c - 'a'] ++;
        }

        for (int right = 0; right < s2.size(); right++){
            freq_s2[s2[right] - 'a']++;

            while (right - left + 1 > s1.size()){
                freq_s2[s2[left] - 'a']--;
                left++;
            }

            if (right - left + 1 == s1.size() && freq_s1 == freq_s2){
                return true;
            }
        }

        return false;

    }
};
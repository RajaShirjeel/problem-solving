class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int startInd = -1;
        int cnt = 0;
        int left = 0;
        unordered_map<char, int>m;

        for (int i = 0; i < t.length(); i++){
            m[t[i]]++;
        }

        for (int right = 0; right < s.length(); right ++){
            if (m[s[right]] > 0) cnt += 1;
            m[s[right]]--;

            while (cnt == t.length()){
                if (right - left + 1 < minLen){
                    minLen = right - left + 1;
                    startInd = left;
                }

                m[s[left]]++;
                if (m[s[left]] > 0) cnt -= 1;
                left ++;
            }
        }   

        return startInd != -1 ? s.substr(startInd, minLen): "";
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for (int i = 0; i < nums.size(); i++){
            temp.push_back(to_string(nums[i]));
        }

        sort(temp.begin(), temp.end(), [](string &s1, string &s2){return s1 + s2 > s2 + s1;});
        string res = "";
        for (auto x: temp){
            res += x;
        }

        while (res[0] == '0' && res.length() > 1){
            res.erase(0, 1);
        }

        return res;
    }
};
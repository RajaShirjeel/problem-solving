class Solution {
public:
    
    void generate(vector<int>&nums, vector<vector<int>>&res, vector<int>&temp, int i){
        if (i == nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        generate(nums, res, temp, i+1);
        temp.pop_back();
        generate(nums, res, temp, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        generate(nums, res, temp, 0);
        return res;
    }
};
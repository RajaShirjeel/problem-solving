class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        map<int, int>mp;
        int maxi = 0;
        int left = 0;
        
        for (int right = 0; right < arr.size(); right++){
            mp[arr[right]]++;
            if (mp.size() > 2){
                mp[arr[left]]--;
                if (mp[arr[left]] <= 0) mp.erase(arr[left]);
                left++;
            }
            if (mp.size() <= 2) maxi = max(maxi, right - left + 1);
        }
        
        return maxi;
    }
};
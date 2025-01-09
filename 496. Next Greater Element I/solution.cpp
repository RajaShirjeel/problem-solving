class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>st;
        unordered_map<int, int>map;

        for (int i = m-1; i >= 0; i--){
            while (!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if (st.empty()){
                map[nums2[i]] = -1;
            }
            else{
                map[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < n; i++){
            if (map.find(nums1[i]) != map.end()){
                nums1[i] = map[nums1[i]];
            }
        }

        return nums1;
        
        
    }
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int lMax = 0;
        int rMax = 0;
        int total = 0;

        while (left < right){
            if (height[left] <= height[right]){
                if (lMax > height[left]){
                    total += lMax - height[left];
                }
                else {
                    lMax = height[left];
                }
                left++;
            }
            else{
                if (rMax > height[right]){
                    total += rMax - height[right];
                }
                else{
                    rMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};
class Solution {
    public:
  
      
      bool isPossible(vector<int>arr, int cows, int val){
          int cowsPlaced = 1;
          int lastPlaced = 0;
          for (int i = 1; i < arr.size(); i++){
              if (arr[i] - arr[lastPlaced] >= val){
                  cowsPlaced ++;
                  lastPlaced = i;
              }
          }
          
          return cowsPlaced >= cows;
      }
  
      int aggressiveCows(vector<int> &stalls, int k) {
  
          // Write your code here
          sort(stalls.begin(), stalls.end());
          int end = stalls[stalls.size() - 1] - stalls[0];
          int ans;
          
          int low = 1;
          int high = end;
          
          while (low <= high){
              int mid = ((low + high) >> 1);
              if (isPossible(stalls, k, mid)){
                  ans = mid;
                  low = mid + 1;
              }
              else {
                  high = mid - 1;
              }
              
          }
          return ans;
          
      }
  };
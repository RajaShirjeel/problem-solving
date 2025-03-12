class Solution {
    public:
    
      static bool comp(pair<int, char> v1, pair<int, char> v2) {
          if (v1.first == v2.first) {
              return v1.second < v2.second; 
          }
          return v1.first < v2.first;
      }
  
  
      int findPlatform(vector<int>& arr, vector<int>& dep) {
  
          vector<pair<int, char>>v;
          for (int i = 0; i < arr.size(); i++){
              v.push_back({arr[i], 'A'});
              v.push_back({dep[i], 'D'});
          }
          
          sort(v.begin(), v.end(), comp);
          
          int maxPlat = 0;
          int platforms = 0;
          
          
          for (int i = 0; i < v.size(); i++){
              if (v[i].second == 'A'){
                  platforms++;
              }
              else {
                  platforms--;
              }
              
              maxPlat = max(maxPlat, platforms);
          }
          
          return maxPlat;
      }
  };
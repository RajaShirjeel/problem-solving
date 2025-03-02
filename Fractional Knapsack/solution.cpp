class Solution {
    public:
    
      static bool comp(const pair<double, int>&v1, const pair<double, int>&v2){
        return (v1.first / (double)(v1.second)) > (v2.first / (double)(v2.second));
      }
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int cap) {
        double totalVal = 0;
        vector<pair<double, int>>v;
        
        for (int i = 0; i < val.size(); i++){
            v.push_back({val[i], wt[i]});
        }
        
        int n = v.size();
        
        sort(v.begin(), v.end(), comp);
        
        for (int i = 0; i < v.size(); i++){
            if (cap < v[i].second){
                totalVal += (v[i].first / (double)(v[i].second)) * cap;
                break;
            }
            else{
                cap -= v[i].second;
                totalVal += v[i].first;
            }
        }
        
        return totalVal;
      }
  };
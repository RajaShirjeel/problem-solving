double minimiseMaxDistance(vector<int> &stations, int k){
	// Write your code here.	
	    int n = stations.size();
        priority_queue<pair<long double, int>>p;
        vector<long double>howMany(n-1, 0);
        for (int i = 1; i < n; i++){
            long double diff = stations[i] - stations[i-1];
            p.push({diff, i-1});
        }
        for (int i = 1; i <= k; i++){
            auto top = p.top();
            p.pop();
            int ind = top.second;
            howMany[ind]++;
            long double diff = stations[ind + 1] - stations[ind];
            long double newSecLen = diff / (howMany[ind] + 1);
            p.push({newSecLen, ind});
            
        }
        
        return p.top().first;
}
int getGasStations(vector<int>arr, long double maxDistance){
	int cnt = 0;
	for (int i = 1; i < arr.size(); i++){
		int numberOfSpaces = (arr[i] - arr[i - 1]) / maxDistance;
		if (arr[i - 1] - arr[i] == maxDistance * numberOfSpaces){
			numberOfSpaces--;
		}
		cnt += numberOfSpaces;
	}

	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	long double low = 0;
	long double high = 0;
	for (int i = 0; i < arr.size()-1; i++){
		high = max(high, (long double)(arr[i + 1] - arr[i]));
	}

	long double diff = 1e-6;

	while (high - low > diff){
		long double mid = (low + high) / 2;
		int cnt = getGasStations(arr, mid);
		if (cnt > k){
			low = mid;
		}
		else{
			high = mid;
		}
	}

	return high;
}
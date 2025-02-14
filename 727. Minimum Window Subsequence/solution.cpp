string minWindow(string s, string t)
{

	int minLen = INT_MAX;
	int minInd = -1;
	
	for (int i = 0; i < s.length(); i++){
		if (s[i] == t[0]){
			int j = 0;
			int k = i;

			while (k < s.length() && j < t.length()){
				if (s[k] == t[j]){
					j++;
				}
				k++;
			}

			if (j == t.length()){
				int end = k - 1;

				j = t.length() - 1;

				while (k - 1 >= i && j >= 0){
					k--;
					if (s[k] == t[j]){
						j--;
					}
				}

				int windowLen = end - k + 1;

				if (windowLen < minLen){
					minLen = windowLen;
					minInd = k;
				}

			}
		}
	}

	return minInd != -1 ? s.substr(minInd, minLen) : "";
}
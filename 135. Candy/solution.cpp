class Solution {
    public:
        int candy(vector<int>& ratings) {
            int i = 1;
            int sum = 1;
    
            while (i < ratings.size()){
                if (ratings[i] == ratings[i - 1]){
                    sum ++;
                    i++;
                    continue;
                }
                
                int peak = 1;
    
                while (i < ratings.size() && ratings[i] > ratings[i - 1]){
                    peak++;
                    sum += peak;
                    i++;
                }
    
                int down = 1;
    
                while (i < ratings.size() && ratings[i] < ratings[i - 1]){
                    sum += down;
                    down++;
                    i++;
                }
    
                if (peak < down){
                    sum += down - peak;
                }
            }
    
            return sum;
        }
};
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>res(boxes.size());
        
        int ballsOnLeft = 0; 
        int opsLeft = 0;
        for (int i = 0; i < boxes.size(); i++){
            res[i] += opsLeft;
            ballsOnLeft += (boxes[i] == '1') ? 1: 0;
            opsLeft += ballsOnLeft;
        }

        int ballsOnRight = 0; 
        int opsRight = 0;
        for (int i = boxes.size()-1; i >= 0; i--){
            res[i] += opsRight;
            ballsOnRight += (boxes[i] == '1') ? 1: 0;
            opsRight += ballsOnRight;
        }
        return res;
    }
};
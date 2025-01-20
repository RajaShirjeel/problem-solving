class Solution {
public:

    void solve(string s, vector<string>&res, vector<string>&segments, int start){
        if (segments.size() == 4){
            if (start == s.length()){
                res.push_back(join(segments));
            }
            return;
        }

        for (int i = 1; i <= 3; i++){
            if (i + start > s.size()) break;
            string segment = s.substr(start, i);
            if (valid(segment)){
                segments.push_back(segment);
                solve(s, res, segments, i + start);
                segments.pop_back();
            }
        }
    }

    bool valid(string segment){
        if (segment[0] == '0' && segment.size() > 1) return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }

    string join(vector<string>segments){
        string ip = "";
        for (auto segment: segments){
            if (!ip.empty()) ip += ".";
            ip += segment;
        }

        return ip;
    }

    int stoi(string segment){
        int res = 0;
        for (auto seg: segment){
            res = res * 10 + (seg - '0');
        }
        return res;
    }


    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        vector<string>segments;
        solve(s, res, segments, 0);
        return res;
    }
};
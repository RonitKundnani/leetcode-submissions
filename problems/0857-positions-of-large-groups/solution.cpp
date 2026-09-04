class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if(s.size() < 3) return {};
        int st = 0,end = 0, cnt = 1, i;
        vector<vector<int>> ans;
        for(i = 0; i < s.size()-1; i++){
            if(s[i] == s[i+1]){
                end = i+1;
                cnt++;
            }
            else{
                if(cnt >= 3) ans.push_back({st,end});
                cnt = 1;
                st = i+1;
            }
        }
        if(cnt >= 3 && end == s.size()-1) ans.push_back({st,end});
        return ans;
    }
};

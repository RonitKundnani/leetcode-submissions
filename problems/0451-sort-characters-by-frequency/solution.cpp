class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256, 0);
        for(char c : s)
            freq[c]++;
        vector<vector<char>> bucket(s.size()+1);
        for(int i = 0; i < 256; i++) {
            if(freq[i]) bucket[freq[i]].push_back(char(i));
        }
        string ans;
        for(int f = s.size(); f >= 1; f--) {
            for(char c : bucket[f]) ans.append(f, c);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int> res;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char ch:p){
            freq1[ch-'a']++;
        }
        int left=0;
        for(int right=0;right<s.size();right++){
            freq2[s[right]-'a']++;
            if(right-left+1>p.size()){
                freq2[s[left]-'a']--;
                left++;
            }
            if(right-left+1==p.size() and freq1==freq2) res.push_back(left);
        }return res;
    }
};

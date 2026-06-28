class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,maxLen=0;
        unordered_set<char> seen;
        for (int right = 0; right < int(s.size()); right++){
            while (seen.count(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen; 
    }
};

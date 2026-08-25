class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> f;
        if(s.size()==1) return 1;
        int cnt=0;
        for(char c:s) f[c]++;
        for(auto&[c,freq]:f){
            if(freq%2) cnt++;
        }return s.size()-cnt+(cnt>0);
    }
};

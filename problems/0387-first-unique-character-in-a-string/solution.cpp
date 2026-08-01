class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> f(26,0);
        for(char c:s){
            f[int(c-'a')]++;
        }
        for(int i=0;i<s.size();i++){
            if(f[int(s[i]-'a')]==1) return i;
        }return -1;

    }
};

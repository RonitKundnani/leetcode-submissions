class Solution {
public:
    int countRotations(string s, int k) {
        int base=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1]) base++;
        }
        if(base==k) ans++;
        for(int i=1;i<s.size();i++){
            int score=base;
            if(s[i-1]==s[i]) score--;
            if(s[s.size()-1]==s[0]) score++;
            if(score==k) ans++;
        }return ans;
    }
};

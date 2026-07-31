class Solution {
public:
    int minimumPushes(string word) {
        vector<int> m(26,0);
        int ans=0;
        for(int i=0;i<word.size();i++){
            m[int(word[i]-'a')]++;
        }
        sort(m.begin(),m.end(),greater<>());
        for(int i=0;i<26;i++){
            if(m[i]!=0){
                if(i<=7) ans=ans+(m[i]*1);
                else if(i<=15) ans=ans+(m[i]*2);
                else if(i<=23) ans=ans+(m[i]*3);
                else ans=ans+(m[i]*4);
            }else{break;}
        }return ans;

    }
};

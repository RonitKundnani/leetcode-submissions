class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        for(char ch:s1){
            freq1[ch-'a']++;
        }
        int windSize=s1.size();
        for(int i=0;i<s2.size();i++){
            int windind=0;
            int ind=i;
            vector<int> freq2(26,0);
            while(windind<windSize and ind<s2.size()){
                freq2[s2[ind]-'a']++;
                windind++;
                ind++;
            }
            if(freq2==freq1) return true;
        }
        return false;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxfreq=0,maxwindow=0,windowlen=0;
        vector<int> freq(26,0);
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxfreq=max(maxfreq,freq[s[right]-'A']);
            windowlen=right-left+1;
            if(windowlen-maxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            windowlen=right-left+1;
            maxwindow=max(maxwindow,windowlen);
        }return maxwindow;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> freq;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }
        int left = 0, right = 0, minwin[2] = {0, int(s.size())}, target = t.size();
        for(;right<s.size();right++){
            char ch = s[right];
            if (freq.find(ch) != freq.end() and freq[ch] > 0) {
                target--;
            }
            freq[ch]--;
            if (target == 0) {
                while (true) {
                    if(freq.find(s[left])!=freq.end() and freq[s[left]]==0)
                        break;
                    freq[s[left]]++;
                    left++;
                }
                if(right-left<minwin[1]-minwin[0]){
                    minwin[0]=left;
                    minwin[1]=right;
                }

                freq[s[left]]++;
                target++;
                left++;
            }
        } return minwin[1]>=s.length()? "":s.substr(minwin[0],minwin[1]-minwin[0]+1);
    }
};

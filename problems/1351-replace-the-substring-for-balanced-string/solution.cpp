class Solution {
public:
    int balancedString(string s) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        int left=0,target=s.size()/4,ans=s.size();
        for(int right=0;right<s.size();right++){
            freq[s[right]]--;
            while(left<s.size() and freq['Q']<=target and freq['W']<=target and freq['E']<=target and freq['R']<=target){
                ans=min(ans,right-left+1);
                freq[s[left]]++;
                left++;
            }
        }return ans;
    }
};

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost){
        int left=0,right=0,curCost=0,ans=0;
        for(;right<s.size();right++){
            curCost+=abs(s[right]-t[right]);
            while(curCost>maxCost){
                curCost-=abs(s[left]-t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }return ans;
    }
};

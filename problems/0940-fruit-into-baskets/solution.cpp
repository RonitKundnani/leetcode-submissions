class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0,ans=0;
        int type1=-1,type2=-1,lastType=-1,lastStart=0;
        for(;right<fruits.size();right++){
            int x = fruits[right];
            if(!(x==type1 or x==type2)) {
                left = lastStart;
                type1 = lastType;
                type2 = x;
            }
            if (x != lastType) {
                lastStart = right;
                lastType = x;
            }
            ans=max(ans,right-left+1);
        }return ans;
    }
};

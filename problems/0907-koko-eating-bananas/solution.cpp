class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=0,ans=-1,mid;
        for(int x:piles) 
            high=max(high,x);
        while(low<=high){
            mid=low+(high-low)/2;
            long long hours=0;
            for(int i=0;i<piles.size();i++) hours+=(piles[i]+mid-1)/mid;
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }return ans;
    }
};

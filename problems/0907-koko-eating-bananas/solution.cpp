class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        int k=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long hours=0;
            for(int i=0;i<piles.size();i++)
                hours=hours+ceil(piles[i]*1.0/mid);
            if(hours<=h){
                k=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }return k;
    }
};

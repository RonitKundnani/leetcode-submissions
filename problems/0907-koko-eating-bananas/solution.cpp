class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9;
        int mid;
        int res = -1;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            long long cnt = 0;
            int f = 0;
            for(int i = 0 ; i < piles.size() ; i++){
                int x = ceil(piles[i]*1.0/mid);
                cnt += x;
            }
            if(cnt <= h){
                f = 1;
            }
            if(f == 1){
                res = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return res;
    }
};

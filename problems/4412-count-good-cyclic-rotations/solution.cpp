class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long dif=0;
        int ans=0;
        for(int i=0;i<n/2;i++){
            dif+=nums[i];
            dif-=nums[i+(n/2)];
        }
        for(int i=0;i<n;i++){
            if(dif>0) ans++;
            dif+=2LL*(nums[(i+n/2)%n]-nums[i]);
        }return ans;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long fsum=0,presum=0;
        int n=nums.size(),cnt=0;
        long long sum=0;
        for(int x:nums) sum+=x;
        for(int i=0;i<(n-1);i++){
            fsum+=nums[i];
            presum=sum-fsum;
            if(fsum>=presum) cnt++;
        }return cnt;
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s=nums[0];
        int curMax=nums[0],curMin=nums[0];
        int maxm=nums[0],minm=nums[0];
        for(int i=1;i<nums.size();i++){
            curMax=max(nums[i],curMax+nums[i]);
            curMin=min(nums[i],curMin+nums[i]);
            maxm=max(maxm,curMax);
            minm=min(minm,curMin);
            s+=nums[i];
        }
        if(maxm<0) return maxm;
        return max(maxm,s-minm);
    }
};

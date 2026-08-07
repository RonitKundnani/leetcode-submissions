class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curMax=nums[0],curMin=nums[0];
        int maxm=nums[0],minm=nums[0];
        int res=abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            curMax=max(nums[i],curMax+nums[i]);
            curMin=min(nums[i],curMin+nums[i]);
            maxm=max(maxm,curMax);
            minm=min(minm,curMin);
            res=max(res,max(abs(minm),maxm));
        }return res;

    }
};

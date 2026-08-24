class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        long long total=0,leftSum=0;
        for(int x: nums)
            total+=x;
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            long long left=1LL*nums[i]*i-leftSum;
            long long rightSum=total-leftSum-nums[i];
            long long right=rightSum-1LL*nums[i]*(n-i-1);
            ans[i]=left+right;
            leftSum+=nums[i];
        }
        return ans;
    }
};

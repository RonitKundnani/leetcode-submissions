class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int lsum=0, rsum=0;
        for(int x:nums) rsum+=x;
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            ans[i]=(rsum>=lsum)?rsum-lsum:lsum-rsum;
            lsum+=nums[i];
        }
        return ans;
    }
};

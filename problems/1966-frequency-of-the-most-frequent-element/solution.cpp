class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        long long cost=0;
        int left=0,right=0;
        sort(nums.begin(),nums.end());
        for(;right<nums.size();right++){
            cost+=nums[right];
            while(1LL*nums[right]*(right-left+1)>1LL*cost+k){
                cost-=nums[left];
                left++;
            }ans=max(ans,right-left+1);
        }return ans;
    }
};

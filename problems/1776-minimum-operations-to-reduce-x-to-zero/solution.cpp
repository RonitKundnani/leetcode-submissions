class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++){sum+=nums[i];}
        sum=sum-x;
        if(sum<0) return -1;
        if(sum==0) return nums.size();
        int left=0,right=0,ans=0,cursum=0;
        for(;right<nums.size();right++){
            cursum+=nums[right];
            while(cursum>sum){
                cursum-=nums[left];
                left++;
            }
            if(cursum==sum)
                ans=max(ans,right-left+1);
        }return ans==0?-1:nums.size()-ans;

    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0,deletion=0,ans=0;
        for(;right<nums.size();right++){
            if(nums[right]==0) deletion++;
            while(deletion>1){
                if(nums[left]==0) {deletion--;}
                left++;
            }ans=max(ans,right-left);
        }return ans;
    }
};

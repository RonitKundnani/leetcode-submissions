class Solution {
public:
    int helper(vector<int>&nums,int k){
        if(k<0) return 0;
        unordered_map<int,int> seen;
        int left=0,right=0,ans=0;
        while(right<nums.size()){
            seen[nums[right]]++;
            while(seen.size()>k){
                seen[nums[left]]--;
                if(seen[nums[left]]==0) seen.erase(nums[left]);
                left++;
            }ans+=right-left+1;
            right++;
        }return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};

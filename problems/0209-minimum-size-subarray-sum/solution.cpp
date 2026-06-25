class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int windowSum=0;
        int count=INT_MAX;
        for (; right < nums.size(); right++){
            windowSum+=nums[right];
            while(windowSum>=target){
                count=min(count,right-left+1); 
                windowSum-=nums[left];
                left++;
            }
        }
        return count==INT_MAX?0:count;
    }
};

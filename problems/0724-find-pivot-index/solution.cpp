class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int cursum=0;
        for(int i=0;i<nums.size();i++){
            if(sum-nums[i]-cursum==cursum) return i;
            cursum+=nums[i];
        }return -1;
    }
};

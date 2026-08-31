class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx=0,maxIdx=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int left=min(minIdx, maxIdx);
        int right=max(minIdx, maxIdx);
        int front=right + 1;
        int back=nums.size()-left;
        int bothSides=(left+1)+(nums.size()-right);
        return min({front,back,bothSides});
    }
};

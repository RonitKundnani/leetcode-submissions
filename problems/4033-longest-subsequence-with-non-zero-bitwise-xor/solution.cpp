class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cnt=0;
        bool check=true;
        for(int i=0;i<nums.size();i++){
            cnt=cnt^nums[i];
            if(nums[i]!=0) check=false;
        }
        if(check) return 0;
        return cnt==0?nums.size()-1:nums.size();
    }
};

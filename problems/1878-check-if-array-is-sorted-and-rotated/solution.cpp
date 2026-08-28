class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        if(nums[0]<nums[nums.size()-1]) cnt++;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) cnt++;
        }return cnt>1?false:true;
    }
};

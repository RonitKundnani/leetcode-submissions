class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //two pointer left at start, right at end
        int left=0,right=nums.size()-1;
        int sum;
        while(left<right){
            sum=nums[left]+nums[right];
            if(sum>target){right--;}
            else if (sum<target){left++;}
            else{return {left+1,right+1};}
        }
        return {};
    }
};

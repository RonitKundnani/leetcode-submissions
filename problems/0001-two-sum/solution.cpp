class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        int complement;
        for (int i = 0; i < int(nums.size()); i++){
            complement=target-nums[i];
            if (seen.count(complement)){return vector<int> {seen[complement],i};}
            seen[nums[i]]=i;
        }  
        return {}; 
    }
};

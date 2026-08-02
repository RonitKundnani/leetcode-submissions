class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int read=0,write=0;
        for(;read<nums.size();read++){
            if(nums[read]!=val){
                nums[write]=nums[read];
                write++;
            }
        }return write;
    }
};

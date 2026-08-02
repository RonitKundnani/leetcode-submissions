class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        for(int n=0;n<nums.size();n++){
            if(nums[n]%2==0){
                swap(nums[i],nums[n]);
                i++;
            }
        }return nums;
    }
};

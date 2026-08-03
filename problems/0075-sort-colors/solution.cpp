class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0;
        int twos=nums.size()-1;
        for(int i=0;i<=twos;i++){
            if(nums[i]==0){
                swap(nums[i],nums[zeros]);
                zeros++;
            }else if(nums[i]==2){
                swap(nums[i],nums[twos]);
                i--;
                twos--;
            }
        }
    }
};

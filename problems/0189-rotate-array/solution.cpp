class Solution {
public:
    void reverse(int low,int high,vector<int>& nums){
        while(low<high){
            swap(nums[high],nums[low]);
            high--;
            low++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0) return;
        reverse(0,nums.size()-1,nums);
        reverse(0,k-1,nums);
        reverse(k,nums.size()-1,nums);
    }
};

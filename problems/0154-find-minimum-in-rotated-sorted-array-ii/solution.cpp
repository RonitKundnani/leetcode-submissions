class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid,minm=INT_MAX;
        while(left<=right){
            mid=left+(right-left)/2;
            minm=min(minm,nums[mid]);
            if(nums[mid]==nums[left]){
                minm=min(minm,nums[mid]);
                left++;
            }
            else if(nums[mid]>=nums[left]){
                minm=min(minm,nums[left]);
                left=mid+1;
            }else{
                minm=min(minm,nums[mid]);
                right=mid-1;
            }
        }return minm;
    }
};

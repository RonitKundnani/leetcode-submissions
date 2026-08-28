class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1,right=n-2,mid;
        if(n==1) return nums[0];
        else if(nums[0]!=nums[1]) return nums[0];
        else if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])   return nums[mid];
            else if((mid%2==1 and nums[mid-1]==nums[mid]) or 
                    (mid%2==0 and nums[mid]==nums[mid+1])) left=mid+1;
            else    right=mid-1;
        }return -1;
    }
};

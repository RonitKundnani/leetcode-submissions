class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int f=0;
        int r=nums.size()-1;
        int mid;
        int st=0;
        while(1){
            mid=(f+r)/2;
            if(nums[mid]==st) break;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                st=nums[mid];
                r=mid-1;
            }
            else{
                st=nums[mid];
                f=mid+1;
            }
        }
        if(target>nums[mid]) return mid+1;
        else if(target<nums[mid]) return mid;
        else return 0;
        return 0;
    }        
};

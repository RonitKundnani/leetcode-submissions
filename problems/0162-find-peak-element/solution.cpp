class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n = nums.size();
         int lo = 1;
         int hi = n - 2;
         int mid;
         if(n == 1){
            return 0;
         }
         if(nums[0] > nums[1]){
            return 0;
         }
         if(nums[n-1] > nums[n-2]){
            return n - 1;
         }
         while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(nums[mid] < nums[mid+1]){
                lo = mid + 1;
            }
            else if(nums[mid] < nums[mid-1]){
                hi = mid - 1;
            }
            else{
                return mid;
            }
         }
         return -1;
    }
};

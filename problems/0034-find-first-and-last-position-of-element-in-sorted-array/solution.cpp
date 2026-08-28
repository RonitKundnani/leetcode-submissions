class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        res.push_back(left);
        res.push_back(right);
        return res;        
    }

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft){
        int left=0,right=nums.size()-1,idx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target)  left = mid + 1;
            else {
                idx = mid;
                if (isSearchingLeft) right = mid - 1;
                else  left = mid + 1;
            }
        }return idx;
    }    
};

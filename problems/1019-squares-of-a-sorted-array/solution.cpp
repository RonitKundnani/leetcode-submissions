class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);    

        int left=0,right=n-1,index=n-1;
        
        while (left<=right){
            int leftval=nums[left]*nums[left],rightval=nums[right]*nums[right];
            if (leftval>=rightval){
                result[index]=leftval;
                left++;
            }
            else{
                result[index]=rightval;
                right--;
            }
            index--;
        }
        
        return result;
    }
};

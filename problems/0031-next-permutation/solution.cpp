class Solution {
public:
    void reverse(int low,int high,vector<int>& nums){
        while(low<high){
            swap(nums[high],nums[low]);
            high--;
            low++;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakingPoint;
        bool edge=true;
        for(int i=n-2;i>-1;i--){
            if(nums[i]<nums[i+1]){
                breakingPoint=i;
                //find smallest element greater then nums[i]
                for(int j=n-1;j>i;j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                edge=false;
                break;
            }
        }
        if(edge) reverse(0,n-1,nums);
        else reverse(breakingPoint+1,n-1,nums);
    }
};

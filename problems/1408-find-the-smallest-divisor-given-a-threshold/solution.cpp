class Solution {
public:
    int func(vector<int>& nums,int x){
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=((nums[i]+x-1)/x);
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minm=1,maxm=*max_element(nums.begin(), nums.end());
        while(minm<maxm){
            int mid=minm+(maxm-minm)/2;
            if(func(nums,mid)<=threshold) maxm=mid;
            else minm=mid+1;
        }return minm;
    }
};

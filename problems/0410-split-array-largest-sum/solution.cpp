class Solution {
public:
    int func(vector<int>& nums, int k,int x){
        long long sum=0LL;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+(long long)nums[i]<=x)
                sum+=(long long)nums[i];
            else{
                cnt+=1;
                sum=(long long)nums[i];
            }
        }return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            int val=func(nums,k,mid);
            if(val<=k){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }return ans;
    }
};

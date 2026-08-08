class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-10000.0;
        int slow=0,fast=k-1;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double avg;
        while(fast<nums.size()){
            double avg=double(sum)/k;
            ans=max(ans,avg);
            if(fast==nums.size()-1) break;
            slow++;
            fast++;
            sum=sum+nums[fast]-nums[slow-1];
        }
        return ans;
    }
};

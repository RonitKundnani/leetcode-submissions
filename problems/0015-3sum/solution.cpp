class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int j,k;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            j=i+1;
            k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j]==nums[j-1] and j<k){j++;}
                }
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else j++;
            }
        }return res;
    }
};

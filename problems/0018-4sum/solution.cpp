class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int j,k;
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int l=0;l<n-3;l++){
            if(l>0 and nums[l]==nums[l-1]) continue;

            for(int i = l+1; i < n-2; i++){
                if(i>l+1 and nums[i]==nums[i-1]) continue;
                j=i+1;
                k=n-1;
                while(j<k){
                    long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        res.push_back({nums[l],nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                        while(j<k and nums[j]==nums[j-1]){j++;}
                        while(j<k and nums[k]==nums[k+1]){k--;}
                    }
                    else if(sum>target) k--;
                    else j++;
                }
            }
        }return res;
    }
};

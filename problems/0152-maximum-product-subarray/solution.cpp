class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(),nums.end());
        int curMax=1,curMin=1;
        for(int val:nums){
            int temp=curMax*val;
            curMax=max({temp,val,curMin*val});
            curMin=min({temp,val,curMin*val});
            res=max(res,curMax);
        }return res;
    }
};

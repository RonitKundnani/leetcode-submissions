class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxm=INT_MIN;
        int minm=INT_MAX;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            maxm=max(nums[i],maxm);
            minm=min(nums[i],minm);
        }
        vector<bool> f(maxm-minm+1,false);
        for(int i=0;i<nums.size();i++){
            f[nums[i]-minm]=true;
        }
        for(int i=0;i<f.size();i++){
            if(!f[i]){
                res.push_back(minm+i);
            }
        }return res;
    }
};

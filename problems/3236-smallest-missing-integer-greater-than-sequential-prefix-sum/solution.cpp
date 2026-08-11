class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        bool f=true;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            if(i>0 and nums[i]==nums[i-1]+1 and f)
                sum+=nums[i];
            else if(i>0) f=false;
        }
        while(s.count(sum)){sum++;}
        return sum;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0) mod+=k;
            if(m.find(mod)!=m.end()){
                cnt+=m[mod];
            }m[mod]+=1;
        }return cnt;
    }
};

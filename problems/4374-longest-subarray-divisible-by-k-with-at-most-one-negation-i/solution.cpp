class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int j=0;j<n;j++){
            long long sum=0;
            unordered_set<int> s;
            for(int z=j;z<n;z++){
                sum+=nums[z];
                int x=((nums[z]%k)+k)%k;
                int val=(2LL*x)%k;
                s.insert(val);
                
                int rem=((sum%k)+k)%k;
                if(rem==0) {
                    ans=max(ans,z-j+1);
                    continue;
                }
                if(s.count(rem)) ans=max(ans,z-j+1);
            }
        }
        return ans;
    }
};

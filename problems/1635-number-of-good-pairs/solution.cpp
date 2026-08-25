class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans=0;
        for(int x:nums) m[x]++;
        for(auto const&[key,value]:m){
            ans+=value*(value-1)/2;
        }return ans;
    }
};

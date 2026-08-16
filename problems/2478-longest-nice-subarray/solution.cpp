class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int left = 0, right = 0, tmp = 0;
        while(right < nums.size()) {
            while(tmp & nums[right]) tmp ^= nums[left++];
            tmp |= nums[right++];
            ans = max(ans, right-left);
        }
        return ans;
    }
};

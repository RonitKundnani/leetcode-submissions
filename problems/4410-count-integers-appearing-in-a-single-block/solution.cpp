class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int>freq(101,0);
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==0 or nums[i]!=nums[i-1])
                freq[nums[i]]++;
        }for(int x:freq){
            if(x==1) res++;
        }return res;
    }
};

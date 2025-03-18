class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fre=0,ans=0;
        for (int i=0;i<nums.size();i++){
            if(fre==0)
                ans=nums.at(i);                
            if(ans==nums.at(i))
                fre++;
            else
                fre--;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int left=0;
        vector<int>res;
        vector<int> freq(101,0);
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]+50]++;
            if(right-left+1>k){
                freq[nums[left]+50]--;
                left++;
            }
            if(right-left+1==k){
                int cnt=0;
                for(int i=-50;i<0;i++){
                    cnt+= freq[i+50];
                    if(cnt>=x){
                        res.push_back(i);
                        break;
                    }
                }
                if(cnt<x) 
                    res.push_back(0);
            }
        }return res;
    }
};

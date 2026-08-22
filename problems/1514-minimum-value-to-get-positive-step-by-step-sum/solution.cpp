class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int min=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<min){
                min=sum;
            }
        }return min>0?1:abs(min)+1;
    }
};

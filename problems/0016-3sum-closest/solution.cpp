class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int j,k;
        int res=INT_MAX;
        int dif=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int curDif=abs(sum-target);
                if(curDif<dif){res=sum;dif=curDif;}
                int sign=sum-target;
                if(sign<0){j++;}
                else{k--;}
            }
        }return res;
    }
};

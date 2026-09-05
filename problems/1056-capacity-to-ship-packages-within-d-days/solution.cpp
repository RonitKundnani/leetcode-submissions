class Solution {
public:
    int func(vector<int> &weights,int x){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>x){
                day=day+1;
                load=weights[i];
            }else load+=weights[i];
        }return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(), 0);
        int low=*max_element(weights.begin(),weights.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(func(weights,mid)<=days) high=mid;
            else low=mid+1;
        }return low;
    }
};

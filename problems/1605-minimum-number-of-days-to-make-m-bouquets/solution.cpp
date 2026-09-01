class Solution {
public:
    bool possible(vector<int>&bloomDay,int m,int k,int day){
        int cnt=0,noOfB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)  cnt++;
            else{
                noOfB+=cnt/k;
                cnt=0;
            }
        }noOfB+=cnt/k;
        if(noOfB>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*1LL*k;
        if(bloomDay.size()<val) return -1;
        int minm=INT_MAX,maxm=INT_MIN;
        for(int x:bloomDay){
            minm=min(minm,x);
            maxm=max(maxm,x);
        }
        while(minm<=maxm){
            int mid=(maxm+minm)/2;
            if(possible(bloomDay,m,k,mid)) maxm=mid-1;
            else minm=mid+1;
        }return minm;
    }
};

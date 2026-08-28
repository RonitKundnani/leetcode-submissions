class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        else{
            int left=1,right=x/2,i,ans=1;
            while(left<=right){
                i=left+(right-left)/2;
                long long sq=1LL*i*i;
                if(sq<x){
                    ans=i;
                    left=i+1;
                }
                else if(sq==x) return i;
                else right=i-1;
            }return ans;
        }
    }   
};

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x<4) return 1;
        int i;
        for( i=1;i<=x/2;i++){
            long long sq=1LL*i*i;
            if(sq<x) continue;
            else if(sq==x) return i;
            else return i-1;
        }return i-1;
    }
};

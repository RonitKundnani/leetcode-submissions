class Solution {
public:
    int reverse(int x) {
        long int r=0;
        while(x!=0){
            r=r*10+x%10;
            x/=10;
        }
        if(r>INT_MAX or r<INT_MIN )
            return 0;
        return r;
    }
};

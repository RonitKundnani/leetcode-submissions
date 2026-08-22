class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0,prod=1;
        int m=n;
        while(n>0){
            int rem=n%10;
            prod*=rem;
            sum+=rem;
            n/=10;
        }
        return m%(sum+prod)==0;
    }
};

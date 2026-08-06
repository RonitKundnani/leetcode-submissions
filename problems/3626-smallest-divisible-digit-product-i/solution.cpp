class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        int product=1;
        for(int i=n;i<=100;i++){
            int temp=i;
            while(temp){
                product*=(temp%10);
                temp/=10;
            }
            if(product%t==0){
                return i;
            }
            product=1;
        }
        return -1;
    }
};

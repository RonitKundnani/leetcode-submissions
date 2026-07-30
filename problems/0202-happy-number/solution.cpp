class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> check;
        while(true){
            if(check.contains(n)) return false;
            else{
                if(n==1) break;
                check.insert(n);
                int next=0;
                while(n){
                    next+=(n%10)*(n%10);
                    n/=10;
                }
                n=next;
            }
        }return true;
    }
};

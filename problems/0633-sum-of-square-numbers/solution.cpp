class Solution {
public:
    bool judgeSquareSum(int c) {
       long int f=int(sqrt(c));
       long int r=0;
       while(f>=r){
        if(f*f+r*r<c){
            r++;
        }else if(f*f+r*r>c){
            f--;
        }
        else{
            return true;
        }
       }return false;
    }
};

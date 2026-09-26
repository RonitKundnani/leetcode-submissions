class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        long long sum_s=0,sum_t=0;
        for(int i=0;i<source.size();i++){
            sum_s+=source[i];
            sum_t+=target[i];
        }if(sum_s==sum_t){
            return true;
        }else return false;
    }
};

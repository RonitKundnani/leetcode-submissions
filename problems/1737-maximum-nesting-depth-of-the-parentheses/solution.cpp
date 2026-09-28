class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,max_cnt=0;
        for(char ch:s){
            if(ch=='('){
                cnt++;
            }else if(ch==')'){
                cnt--;
            }max_cnt=max(max_cnt,cnt);
        }return max_cnt;
    }
};

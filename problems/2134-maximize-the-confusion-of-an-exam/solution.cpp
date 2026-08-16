class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0,right=0,maxT=0,cntT=0,maxF=0,cntF=0;
        for(;right<answerKey.size();right++){
            char x=answerKey[right];
            if(x=='T') cntT++;
            while(cntT>k){
                if(answerKey[left]=='T') cntT--;
                left++;
            }maxT=max(maxT,right-left+1);
        }
        left=0;
        for(right=0;right<answerKey.size();right++){
            char x=answerKey[right];
            if(x=='F') cntF++;
            while(cntF>k){
                if(answerKey[left]=='F') cntF--;
                left++;
            }maxF=max(maxF,right-left+1);
        }
        return max(maxF,maxT);
    }
};

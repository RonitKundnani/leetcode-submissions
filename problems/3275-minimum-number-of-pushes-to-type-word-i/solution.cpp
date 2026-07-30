class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<9) return n;
        else if(n<17) return (n-8)*2+8;
        else if(n<25) return (n-16)*3+24;
        else return (n-24)*4+48;
    }
};

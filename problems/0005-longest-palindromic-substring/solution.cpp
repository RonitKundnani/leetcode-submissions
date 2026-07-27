class Solution {
public:
    int  expand(string s, int left,int right){
        while(left>=0 and right<s.length() and s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int left=0;
        int right=0;
        for(int i=0;i<s.length();i++){
            int odd=expand(s,i,i);
            int even=expand(s,i,i+1);
            int max_len=max(odd,even);

            if (max_len>right-left){
                left=i-(max_len-1)/2;
                right=i+max_len/2;
            }
        }return s.substr(left,right-left+1);
    }
};

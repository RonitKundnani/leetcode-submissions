class Solution {
public:
    string reverseWords(string s) {
        int end=0,start=0;
        while(end<s.size()){
            if(s[end]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start=end+1;
            }end++;
        }reverse(s.begin()+start,s.end());
        return s;
    }
};

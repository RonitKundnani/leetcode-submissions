class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.size()-1;
        while(end>=0 and s[end]==' '){
            end--;
        }
        int start=end;
        while(start>=0 and s[start]!=' '){
            start--;
        }return end-start;
    }
};

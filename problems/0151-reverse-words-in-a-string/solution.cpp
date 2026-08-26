class Solution {
public:
    string r(string s) {
        reverse(s.begin(), s.end());
        int start = 0, end = 0;
        while (end < s.size()) {
            if (s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
            end++;
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
    string reverseWords(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!ans.empty() && ans.back() != ' ')
                    ans += ' ';
            } else {
                ans += s[i];
            }
        }
        if (!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        return r(ans);
    }
};

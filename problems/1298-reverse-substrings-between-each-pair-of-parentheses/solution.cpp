class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans="";
        for(char ch:s){
            if(ch=='('){
                st.push(int(ans.size()));
            }else if(ch==')'){
                int strt=st.top();
                st.pop();
                reverse(ans.begin()+strt,ans.end());
            }else{
                ans+=ch;
            }
        }return ans;
    }
};

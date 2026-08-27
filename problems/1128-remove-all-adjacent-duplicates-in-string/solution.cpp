class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        for(char c:s){
            if(!st.empty() and c==st.back()){
                st.pop_back();
            }
            else{
                st.push_back(c);
            }
        }
        string ans;
        for(int i=0;i<st.size();i++) ans+=st[i];
        return ans;
    }
};

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;
        for(string operation:operations){
            if(operation=="+"){
                string x=st.top();
                st.pop();
                int y=stoi(st.top());
                st.push(x);
                st.push(to_string(stoi(x)+y));
            }else if(operation=="D"){
                int x=stoi(st.top());
                st.push(to_string(2*x));
            }else if(operation == "C"){
                st.pop();
            }
            else{
                st.push(operation);
            }
        }int ans=0;
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }return ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = int(temperatures.size());
        vector<int> res(n,0);
        int temp;
        for(int i = 0; i < n; i++){
            while(!st.empty() and temperatures[i]>temperatures[st.top()]){
                temp=st.top();
                st.pop();
                res[temp]=i-temp;
            }
            st.push(i);
        }
        return res;
    }
};

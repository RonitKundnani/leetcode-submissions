class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string op : tokens) {
            if (op == "+" || op == "-" || op == "*" || op == "/") {
                int x = st.top();
                st.pop();

                int y = st.top();
                st.pop();

                if (op == "+") st.push(y + x);
                else if (op == "-") st.push(y - x);
                else if (op == "*") st.push(y * x);
                else st.push(y / x);
            }
            else {
                st.push(stoi(op));
            }
        }

        return st.top();
    }
};

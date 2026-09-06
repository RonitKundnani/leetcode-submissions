class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        if(n==1) return 1;
        vector<int> s,p;
        for(int i=0;i<n;i++){
            if(!p.empty() and position[i]-p.back()<=distance){
                p.back()=position[i];
                s.back()=speed[i];
            }else{
                p.push_back(position[i]);
                s.push_back(speed[i]);
            }
        }
        int groups=p.size();
        vector<int> st;
        for(int i=groups-1;i>=0;i--){
            if(st.empty()){
                st.push_back(i);
                continue;
            }int j=st.back();
            if(p[j]-p[i]<=distance or s[i]>s[j]) continue;
            st.push_back(i);
        }return st.size();
    }
};

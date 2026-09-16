class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int ans=speed.size();
        int fspd=speed[speed.size()-1];
        for(int i=speed.size()-2;i>=0;i--){
            if(fspd<speed[i]||(position[i+1]-position[i]<=distance)){
                ans--;
            }
            else fspd=speed[i];
        }
        return ans;
    }
};

class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<vector<int>>& isConnected){
        vis[node]=1;
        for(int x=0;x<isConnected.size();x++){
            if(isConnected[node][x] == 1 and !vis[x]){
                dfs(x,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        // vis[0]=1;
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,isConnected);
            }
        }return ans;
    }
};


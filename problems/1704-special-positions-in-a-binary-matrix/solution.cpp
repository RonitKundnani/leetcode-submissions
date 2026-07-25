class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<int> row(rows,0);
        vector<int> col(cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1 and row[i]==1 and col[j]==1){
                    ans++;
                }
            }
        }return ans;
    }
};

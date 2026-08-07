class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int deleted=-10000;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevnodelete=nodelete;
            int prevdelete=deleted;
            deleted=max(prevnodelete,prevdelete+arr[i]);
            nodelete=max(arr[i],prevnodelete+arr[i]);
            ans=max({ans,nodelete,deleted});
        }return ans;
    }
};

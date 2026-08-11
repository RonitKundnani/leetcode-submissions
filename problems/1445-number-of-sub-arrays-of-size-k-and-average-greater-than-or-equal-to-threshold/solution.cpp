class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(k>arr.size()) return -1;
        int left=0;
        int sum=0;
        int cnt=0;
        for(int right=0;right<arr.size();right++){
            sum+=arr[right];
            if((right-left+1)>k){
                sum-=arr[left];
                left++;
            }
            if(right-left+1==k and (sum/k)>=threshold){
                cnt++;                
            }
        }return cnt;
    }
};

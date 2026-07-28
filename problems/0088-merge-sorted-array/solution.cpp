class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0) nums1=nums2;
        if(n==0) return;
        int r1=m-1;
        int r2=n-1;
        int index=m+n-1;
        while(r1>-1 and r2>-1){
            if(nums1[r1]>nums2[r2]){
                nums1[index]=nums1[r1];
                r1--;
            }else{
                nums1[index]=nums2[r2];
                r2--;
            }index--;
        }
        if(r1==-1){
            while(r2>-1){
                nums1[index]=nums2[r2];
                index--;
                r2--;
            }
        }
        else{
            while(r1>-1){
                nums1[index]=nums1[r1];
                index--;
                r1--;
            }
        }
    }
};

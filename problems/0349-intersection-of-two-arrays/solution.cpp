class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> freq;
        for(int i=0;i<nums1.size();i++) freq.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(freq.count(nums2[i])){
                res.push_back(nums2[i]);
                freq.erase(nums2[i]);
            }
        }return res;
    }
};
